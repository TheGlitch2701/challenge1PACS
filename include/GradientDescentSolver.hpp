#include "Point.hpp"
#include "muparserX_fun.hpp"
#include <fstream>

#ifndef GRADIENTDESCENTSOLVER_HPP_
#define GRADIENTDESCENTSOLVER_HPP_

class GradientDescentSolver{
    public:
            GradientDescentSolver(const MuparserXFun &, const std::vector<MuparserXFun> &,
            const unsigned int &, const double &, const double &,
            const double &, const std::string &, const double &mu = 0.2, const double &sigma = 0.25,
            const bool &exact = false ,const double &h = 1e-6, const std::string &FDM_type = "CD");

            double Solver(Point &);

            double forwardDisc(Point &, Point &, MuparserXFun &, size_t);
            double backwardDisc(Point &, Point &, MuparserXFun &, size_t);
            double centeredDisc(Point &, Point &, Point &, MuparserXFun &, size_t);

            void finiteDifferencesMethod(Point &, Point &, Point &, double &);
            void exactGradientMethod(Point &, Point &, Point &, double &);

            double inverseDecay(const double &, const unsigned int &);
            double exponentialDecay(const double &, const unsigned int &);
            double lineSearch(Point &,const double &, Point &);

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
        const bool exact = false;
        const double h = 1e-6;
        const std::string FDM_type = "CD";
};

#endif