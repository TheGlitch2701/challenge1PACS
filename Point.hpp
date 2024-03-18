#include <vector>
#include <iostream>
#include <cmath>
#ifndef POINT_HPP_
#define POINT_HPP_

class Point{
    private:
        unsigned int n = 2;
        std::vector<double> points = {0.,0.};

    public:
        Point(unsigned int,std::vector<double> &);
        Point(unsigned int);
        Point(Point &);
        //Point()=default;

        void setPoints(const std::vector<double> &);
        void setPoint(const double &, size_t &);
        const std::vector<double>getPoints();
        const unsigned int getN();

        void print() const;
        double norm();
        double distance(Point &, Point &);
};

Point operator-(Point &, Point &);
Point operator*(double &, Point &);

#endif