#include "Point.hpp"
#include "muparserX_fun.hpp"

#ifndef GRADIENTDESCENTSOLVER_HPP_
#define GRADIENTDESCENTSOLVER_HPP_

class GradientDescentSolver{
    public:
            GradientDescentSolver(const MuparserXFun &, const std::vector<MuparserXFun> &,
            const unsigned int &, const double &, const double &,
            const double &, const std::string &, const double &mu = 0.2, const double &sigma = 0.);

            double Solver(Point &);

            double inverseDecay(const double &, const unsigned int &);

            double exponentialDecay(const double &, const unsigned int &);

            double lineSearch(Point &,const double &, Point &); // to be implemented

    private:
        MuparserXFun fun;
        std::vector<MuparserXFun> dfuns;
        const unsigned int max_it;
        const double eps_step;
        const double eps_res;
        const double a0;
        const std::string rate_rule;
        const double mu = 0.2;
        const double sigma = 0.25;
};

#endif