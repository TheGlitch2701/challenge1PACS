#include "GradientDescentSolver.hpp"

/*CONSTRUCTOR of GradientDescentSolver*/
GradientDescentSolver::GradientDescentSolver(const MuparserXFun &fun, const std::vector<MuparserXFun> &dfuns,
 const unsigned int &max_it, const double &eps_step, const double &eps_res, const double &a0, const std::string &rate_rule,
 const double &mu, const double &sigma, const bool &exact, const double &h, const std::string &FDM_type)
: fun(fun), max_it(max_it), eps_step(eps_step), eps_res(eps_res), a0(a0), rate_rule(rate_rule), mu(mu), sigma(sigma), 
    exact(exact),h(h),FDM_type(FDM_type)
{
    for(size_t i = 0; i < dfuns.size(); ++i)
        this->dfuns.emplace_back(dfuns[i]);
};


/*RATE RULE : EXPONENTIAL DECAY
See Challenge23-24-1.pdf for further documentation*/
double GradientDescentSolver::exponentialDecay(const double &a0, const unsigned int &k){
    return a0 * std::exp(-(this->mu*k));    
}


/*RATE RULE: INVERSE DECAY
See Challenge23-24-1.pdf for further documentation*/
double GradientDescentSolver::inverseDecay(const double &a0, const unsigned int &k){
    return a0/(1 + this->mu*k);
}


/*RATE RULE: LINE SEARCH (ARMIJO'S RULE)
See Challenge23-24-1.pdf for further documentation*/
double GradientDescentSolver::lineSearch(Point &p, const double &sigma,Point &grad){
    double rhs, lhs, ak = 2*this->a0;
    
    /*I needed to create an auxilliary Point which is a copy of grad because I
    will need both the modified gradient and the original one*/
    Point aux_grad(grad), aux_p(p);

    // I had to add an auxilliary MuparserXFun because otherwise it will raise
    // a segmentation fault error when Eval() method is done in muparserX_fun.hpp
    MuparserXFun aux_fun(fun);
    
    do{
        ak /= 2;
        aux_grad = ak * grad;
        aux_p = p - aux_grad;
        lhs = aux_fun(p) - aux_fun(aux_p);
        rhs = this->sigma * ak * pow(grad.norm(),2);
        //@note better set a maximum number of iterations to avoid infinite loops
        // Even if Armijo should converge for sufficiently regular functions, 
        // roud-off errors may cause the loop to be infinite in nasty situations.
        // In which case you sto the search after a max number of interations.
    }while(lhs < rhs);
    return ak;
}

double GradientDescentSolver::centeredDisc(Point &p, Point &prev, Point &succ, MuparserXFun &funct, size_t k){
/*CENTERED DISCRETIZATION for Gradient*/

    double aux = p.getPoints()[k];
    prev.setPoint(aux - this->h,k);
    succ.setPoint(aux + this->h,k);
    
    return (funct(succ) - funct(prev)) / (2*this->h);
}

double GradientDescentSolver::forwardDisc(Point &p, Point &succ, MuparserXFun &funct, size_t k){
/*FORWARD DISCRETIZATION for Gradient*/
    double aux = p.getPoints()[k];
    succ.setPoint(aux + this->h,k);
        
    return (funct(succ) - funct(p)) / (this->h);
}

double GradientDescentSolver::backwardDisc(Point &p, Point &prev, MuparserXFun &funct, size_t k){
/*BACKWARD DISCRETIZATION for Gradient*/
    double aux = p.getPoints()[k];
    prev.setPoint(aux - this->h,k);
    
    return (funct(p) - funct(prev)) / (this->h);
}

void GradientDescentSolver::finiteDifferencesMethod(Point &grad, Point &p, Point &step, double &ak){
/*Compute the Finite Differences Method for the Gradient of
the function when the exact gradient is not provided.
This method has the same structure of the one with the
Exact Gradient but it also compute the CD, FD or BD 
of the Gradient in the for-loop*/

    Point prev(p);
    Point succ(p);
    Point aux_p(p);
    
    MuparserXFun aux_fun(fun);
    double aux = 0.;

    for(size_t k = 0; k < grad.getN();++k){
        //@note Even if a but more verbose, it is better not to have the if inside
        // a tight loop. Moving the if externally makes the code more efficient
        if(this->FDM_type == "CD")
            aux = centeredDisc(aux_p,prev,succ,aux_fun,k);
        else if(this->FDM_type == "FD")
            aux = forwardDisc(aux_p,succ,aux_fun,k);
        else
            aux = backwardDisc(aux_p,prev,aux_fun,k);
                        
        grad.setPoint(aux,k);
        p.setPoint(step.getPoints()[k] - ak * grad.getPoints()[k],k);
    }
}

void GradientDescentSolver::exactGradientMethod(Point &gradients, Point &p, Point &step, double &ak){
/*Compute the update of the vector of gradients by using
the EXACT GRADIENT defined by the user in the data.txt file*/

    for(size_t j = 0; j < this->dfuns.size(); ++j){
        gradients.setPoint(dfuns[j](step),j);
        p.setPoint(step.getPoints()[j] - ak * gradients.getPoints()[j],j);
    }
}

/*This function compute the Gradient Descent Method starting from
point p (user defined).
See Challenge23-24-1.pdf for further documentation.*/
double GradientDescentSolver::Solver(Point &p){

        std::ofstream points_file("plot_script/points.dat");

        Point step = p;
        Point gradients(p.getPoints().size());
        size_t i = 0;
        double ak = this->a0;

        unsigned int r;

        if (this->rate_rule == "exponential decay")
            r = 1;
        else if (this->rate_rule == "inverse decay")
            r = 2;
        else if (this->rate_rule == "line search")
            r = 3;
        else{
            std::cout << "Updating Method for the Learning Rate (a0) not valid!" << std::endl;
            return 0.;
        }
//@note it is better not to put outputs to the terminal from inside a low-level function
// pass the results to the caller and print at a higher level. Exceptions: when debugging.

        if(exact)
            std::cout << "Minimizing the function:\n\n" + fun.getM_s() << "\n\nusing "<<rate_rule<<
        " and exact gradient.\n"<<std::endl;
        else
            std::cout << "Minimizing the function:\n\n" + fun.getM_s() << "\n\nusing "<<rate_rule<<
        " and Finite Differences Method for the Gradient: " + this->FDM_type<<".\n"<<std::endl;

        while(i < this->max_it){

            if(points_file.is_open()){
                for(size_t j = 0; j < p.getN(); ++j)
                    points_file << p.getPoints()[j] << "\t";
                points_file << "\n";
            }else
                std::cerr << "Error opening file!\n"<< std::endl;
            
            // Update of the vector of Gradients
            
            if(this->exact)
                exactGradientMethod(gradients,p,step,ak);
            else
                finiteDifferencesMethod(gradients,p,step,ak);

            /*See if convergence is reached*/

            if((p - step).norm() < this->eps_step or gradients.norm() < this->eps_res){
                std::cout << "Gradient Descent converges in " << i << " iterations " <<
                "at the minimum: ";
                p.print();
                points_file.close();
                return this->fun(p);
            }

            // Next step 

            ++i;
            
            // Choice of the Rate Rule

            switch(r){

                case 1:
                    ak = this->exponentialDecay(this->a0,i);

                case 2:
                    ak = this->inverseDecay(this->a0,i);

                case 3:
                    ak = this->lineSearch(step,this->sigma,gradients);
            }

            // Updating step = p (x_(k+1) = x_k)

            step.setPoints(p.getPoints());
    }

    std::cout << "Gradient Descent doesn't converged in the maximum number of iterations ( " << i <<" )" << std::endl;
    points_file.close();
    return this->fun(p);
}