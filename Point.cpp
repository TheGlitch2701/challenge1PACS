#include "Point.hpp"


// CONSTRUCTORS OF POINT
Point::Point(unsigned int dim, std::vector<float> &value)
{
    this->n = dim;
    for(unsigned int i = 0; i < n; ++i)
        this->points[i] = value[i];
}

Point::Point(unsigned int dim){
    this->n = dim;
    for(unsigned int i = 0; i < n; ++i)
        this->points[i] = 0.;
}


// get and set function and other utility as print
void Point::setPoints(const std::vector<float> &v){
    if(n != v.size()){
        std::cout << "Vectors have different sizes!!!"<<std::endl;
        return;
    }
    for(size_t i = 0; i < n; ++i)
        points[i] = v[i];
}


const std::vector<float> Point::getPoints(){
    return points;
}

const unsigned int Point::getN(){
    return this->n;
}


void Point::print()const {
    std::cout<<"(";
    for(size_t i = 0; i < n; ++i){
        std::cout<< points[i];
        if(i != n-1)
            std::cout<<",";
    }
    std::cout<<")"<<std::endl;
}

double Point::norm(Point &p){
    double sum = 0.;

    for(size_t i = 0; i < p.getN(); ++i)
        sum += p.getPoints()[i];
    return sqrt(sum);
}

double Point::distance(Point &p1, Point &p2){
    
    Point diff = p1-p2;
    return norm(diff);
    
}

// OVERLOADING 

Point operator-(Point &a, Point &b)
{
    if(a.getN() != b.getN()){
        std::cerr<< "Sizes are different.\nCannot perform difference operation."<<std::endl;
        return Point(0);
    }

    std::vector<float> aux;
    for(size_t i = 0; i < a.getN(); ++i){
        aux.emplace_back(a.getPoints()[i] - b.getPoints()[i]);
    }
    return Point(a.getN(),aux);
}

Point operator*(float &a, Point &p){
    std::vector<float> aux;
    for(size_t i = 0; i < p.getN(); ++i){
        aux.emplace_back(a*p.getPoints()[i]);
    }
    return Point(p.getN(),aux);
}