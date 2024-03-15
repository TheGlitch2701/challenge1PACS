// This will be the main function of my program for GRADIANT DESCENT

// Here I introduce all the library I need for the execution

#include <cmath>
#include <vector>
#include <iostream>
#include "Point.hpp"
#include "GetPot"
#include "muparser_fun.hpp"

/*double fun(const std::vector<double> &x){
    return x[0]*x[1] + 4*x[0]*x[0]*x[0]*x[0] + x[1]*x[1] + 3*x[0];
}

double dfunx1(const std::vector<double> &x){
    return x[1] + 16*x[0]*x[0]*x[0] + 3;
}


double dfunx2(const std::vector<double> &x){
    return x[0] + 2*x[1];
}*/

double exponentialDecay(const double &a0, const unsigned int &k){
    double mu = 0.2;
    return a0 * std::exp(-mu*k);    
}

double inverseDecay(const double &a0, const unsigned int &k){
    double mu = 0.2;
    return a0/(1 + mu*k);
}

// To be implemented
double LineSearch(){

    return 0;
}

double norm(std::vector<double> &x){
    return sqrt(x[0]*x[0] + x[1]*x[1]);
}

/*std::vector<double> GradientDescent(std::vector<double> &x0, const double &eps_step,
                                    const double &eps_res, const unsigned int &k,
                                    const double &a0){

    std::vector<double> x1 = x0; // COPY-ASSIGNMENT
    std::vector<double> gradf = {0,0};
    std::vector<double> diff = {0,0};

    double ak = a0;

    for(size_t i = 0; i < k; ++i){
        gradf[0] = ak * dfunx1(x0);
        gradf[1] = ak * dfunx2(x0);

        x1[0] = x0[0] - gradf[0];
        x1[1] = x0[1] - gradf[1];

        diff[0] = x1[0] - x0[0];
        diff[1] = x1[1] - x0[1];

        if(norm(gradf) < eps_res or norm(diff)  < eps_step){
            std::cout << "Algorithm Converged to the solution: " <<
                 "(" << x1[0] <<" "<<x1[1]<<") in "<< i << " iteration." << std::endl;
        
            x0[0] = x1[0];
            x0[1] = x1[1];
            return x0;
        }
        
        x0[0] = x1[0];
        x0[1] = x1[1];

        ak = exponentialDecay(a0,i);
        //ak = inverseDecay(a0,i);
    }

    return x0;
}*/



int main(int argc, char **argv){

    std::vector<double> start_point = {0,0};

    GetPot            command_line(argc, argv);
    const std::string filename = command_line.follow("data.txt", 2, "-f", "--file");

    GetPot            datafile(filename.c_str());
    const std::string section = "GradientDescent/";

    const unsigned int max_it   = datafile((section + "max_it").data(),100);
    const double eps_step       = datafile((section + "tol_step").data(),1e-6);
    const double eps_res        = datafile((section + "tol_res").data(),1e-6);
    const double learning_rate  = datafile((section + "learning_rate").data(),0.1);
    const std::string rate_rule = datafile((section + "rate_rule").data(),"exponential decay");

    std::string funString = datafile((section + "fun").data(), " ");
    std::string dfunString = datafile((section + "dfun").data(), " ");
    

    MuparserFun fun(funString);
    MuparserFun dfun(dfunString);

    std::cout << "Codice eseguito" << std::endl;


   /* GradientDescent(start_point,eps_step,eps_res,max_it,learning_rate);

    std::cout << fun(start_point) <<std::endl;*/
    

   /*
    double a = 2.5;
    std::vector<double> start_point = {0,0};
    std::vector<double> point = {3,2};
    Point p(2,start_point);
    Point v(2,point);
    p.print();
    v.print();
    Point diff = p-v;
    diff.print();
    diff = a*diff;
    diff.print();*/
    return 0;
}

// NEED TO IMPLEMENT GETPOT & MUPARSERX AND THEN REFACTORY ALL THE CODE TO USE
// MORE THAN 2 VARIABLES