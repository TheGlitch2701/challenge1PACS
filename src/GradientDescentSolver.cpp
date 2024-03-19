#include "GradientDescentSolver.hpp"

/*CONSTRUCTOR of GradientDescentSolver*/
GradientDescentSolver::GradientDescentSolver(const MuparserXFun &fun, const std::vector<MuparserXFun> &dfuns,
 const unsigned int &max_it, const double &eps_step, const double &eps_res, const double &a0, const std::string &rate_rule,
 const double &mu, const double &sigma)
: fun(fun), max_it(max_it), eps_step(eps_step), eps_res(eps_res), a0(a0), rate_rule(rate_rule), mu(mu), sigma(sigma)
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
    }while(lhs < rhs);
    return ak;
}


/*This function compute the Gradient Descent Method starting from
point p (user defined).
See Challenge23-24-1.pdf for further documentation.*/
double GradientDescentSolver::Solver(Point &p){

        Point step = p;
        Point gradients(p.getPoints().size());
        size_t i = 0;
        double ak = this->a0;

        rate_rule == "";

        unsigned int r;

        if (this->rate_rule == "exponential decay")
            r = 1;
        else if (this->rate_rule == "inverse decay")
            r = 2;
        else if (this->rate_rule == "line search")
            r = 3;
        else{
            std::cout << "Upgrading Method for the Learning Rate (a0) not valid!" << std::endl;
            return 0.;
        }

        std::cout << "Minimizing the function:\n\n" + fun.getM_s() << "\n\nusing "<<rate_rule<<".\n"<<std::endl;

        while(i < this->max_it){
        
        // Update of the vector of Gradients
        
        for(size_t j = 0; j < this->dfuns.size(); ++j){
            gradients.setPoint(dfuns[j](step),j);

            p.setPoint(step.getPoints()[j] - ak * gradients.getPoints()[j],j);
        }

        /*See if convergence is reached*/

        if((p - step).norm() < this->eps_step or gradients.norm() < this->eps_res){
            std::cout << "Gradient Descent converges in " << i << " iterations " <<
            "at the minimum: ";
            p.print();
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
    return this->fun(p);
}