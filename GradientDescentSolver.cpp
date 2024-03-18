#include "GradientDescentSolver.hpp"


GradientDescentSolver::GradientDescentSolver(const MuparserXFun &fun, const std::vector<MuparserXFun> &dfuns,
 const unsigned int &max_it, const double &eps_step, const double &eps_res, const double &a0, const std::string &rate_rule,
 const double &mu)
: fun(fun), max_it(max_it), eps_step(eps_step), eps_res(eps_res), a0(a0), rate_rule(rate_rule), mu(mu)
{
    for(size_t i = 0; i < dfuns.size(); ++i)
        this->dfuns.emplace_back(dfuns[i]);
};

double GradientDescentSolver::exponentialDecay(const double &a0, const unsigned int &k){
    return a0 * std::exp(-(this->mu*k));    
}

double GradientDescentSolver::inverseDecay(const double &a0, const unsigned int &k){
    return a0/(1 + this->mu*k);
}

double GradientDescentSolver::lineSearch(){
    return 0.;
}

double GradientDescentSolver::Solver(Point &p){

    Point step = p;
    Point gradients(p.getPoints().size());
    size_t i = 0;
    double ak = this->a0;

    //std::cout << "Prima del while" <<std::endl;

    while(i < this->max_it){
        
        // Upgrade of the vector of Gradients

        //std::cout << "Prima del for per la definizione del gradiente: " << i << std::endl;
        
        for(size_t j = 0; j < this->dfuns.size(); ++j){
            // setPoint modified a single element of the vector of points in p
            // while setPoints modified the whole vector of points
            
            gradients.setPoint(dfuns[j](step),j);

            p.setPoint(step.getPoints()[j] - ak * gradients.getPoints()[j],j);
        }

        //std::cout << "Prima del controllo di uscita se converge " << i << std::endl;

        if((p - step).norm() < this->eps_step or gradients.norm() < this->eps_res){
            std::cout << "Gradient Descent converges in: " << i << " iterations" <<
            "at the minimum: ";
            p.print();
            return this->fun(p);
        }

        step.setPoints(p.getPoints());

        ++i;
        //std::cout << "Prima del controllo per aggiornamento a0 "<< i << std::endl;
        if (this->rate_rule.compare("exponential decay"))
            ak = this->exponentialDecay(this->a0,i);
        else if (this->rate_rule.compare("inverse decay"))
            ak = this->inverseDecay(a0,i);
        else if (this->rate_rule.compare("line search"))
            ak = this->lineSearch();
        else{
            std::cout << "Upgrading Method for the Learning Rate (a0) not valid!" << std::endl;
            return 0.;
        }
    }

    std::cout << "Gradient Descent doesn't converged in the maximum number of iterations" << std::endl;
    return this->fun(p);
}