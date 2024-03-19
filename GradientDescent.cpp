// This will be the main function of my program for GRADIANT DESCENT

// Here I introduce all the library I need for the execution

#include <iostream>
#include "Point.hpp"
#include "lib/GetPot"
#include "muparserX_fun.hpp"
#include "GradientDescentSolver.hpp"


int main(int argc, char **argv){

    /*Here we find the section related to the "READING FROM data.txt"*/

    GetPot            command_line(argc, argv);
    const std::string filename = command_line.follow("data.txt", 2, "-f", "--file");

    GetPot            datafile(filename.c_str());
    const std::string section = "GradientDescent/";

    /*Here I couldn't find how to read directly from the data.txt a vector 
    of doubles, so I found online that this is a possible solution.
    Obviously it is not highly performant, but it suits the purpose.*/

    std::vector<std::string> dfunsString;
    std::string x0 =datafile((section + "start").data()," ");
    std::istringstream stm(x0) ;
    std::vector<double> start_point;
    double n ;
    while( stm >> n ) start_point.emplace_back(n) ;

    const unsigned int max_it   = datafile((section + "max_it").data(),100);
    const double eps_step       = datafile((section + "tol_step").data(),1e-6);
    const double eps_res        = datafile((section + "tol_res").data(),1e-6);
    const double learning_rate  = datafile((section + "learning_rate").data(),0.1);
    const std::string rate_rule = datafile((section + "rate_rule").data(),"exponential decay");
    const size_t dim            = datafile((section + "dim").data(),0);
    const double mu             = datafile((section + "mu").data(),0.2);
    const double sigma          = datafile((section + "sigma").data(),0.25);


    // funString contains the string identifing our function to minimize
    std::string funString       = datafile((section + "fun").data()," ");
        
    /*Since when we work with functions with more than 1 variable we come into GRADIENTS.
    I define a vector which will contain all the string of the gradients w.r.t every variable (x0,x1,x2,...)*/
    std::vector<MuparserXFun>     dfuns;

    Point start(dim,start_point);


    /*In this section we create the "real" function. In fact the class MuparserXFun uses the library muparserx to parse the variables
    of the function directly from a std::string and can evaluate the value of a MuparserXFun in a Point class member.*/
    MuparserXFun fun(funString, start, dim);

    /*Just recall we are in dim >= 2 so the gradients will be a vector of MuparserXFun*/
    for(size_t i = 0; i < dim; ++i){
        dfunsString.emplace_back(datafile((section + "dfun" + std::to_string(i)).data(), " "));
        MuparserXFun dfun(dfunsString[i], start, dim);
        dfuns.emplace_back(dfun);
    }


    /*Here I instantiate the Gradient Descent Solver passing it all the requirments.
    In the end we print the minimum of our function if found, 0. otherwise*/

    GradientDescentSolver solver(fun,dfuns,max_it,eps_step,eps_res,learning_rate,rate_rule,mu,sigma);

    double result = solver.Solver(start);

    std::cout << "Value of the function in the last iteration: " << result << std::endl;

    return 0;
}
