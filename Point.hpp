#include <vector>
#include <iostream>
#include <cmath>
#ifndef POINT_HPP_
#define POINT_HPP_

class Point{
    private:
        unsigned int n = 2;
        std::vector<float> points = {0.,0.};

    public:
        Point(unsigned int,std::vector<float> &);
        Point(unsigned int);

        void setPoints(const std::vector<float> &);
        const std::vector<float>getPoints();
        const unsigned int getN();

        void print() const;
        double norm(Point&);
        double distance(Point &, Point &);
};

Point operator-(Point &, Point &);
Point operator*(float &, Point &);

#endif