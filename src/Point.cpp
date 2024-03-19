#include "Point.hpp"


// CONSTRUCTORS OF POINT

/*Constructor if we pass the dimension in which we are working and
an std::vector<double> which contains the value of the every
variable.
Return a Point.*/
Point::Point(unsigned int dim, std::vector<double> &value)
{
    this->n = dim;
    for(unsigned int i = 0; i < n; ++i)
        this->points[i] = value[i];
}

/*Constructor if we pass the dimension in which we are working.
The values of each variable is assigned 0. as default.
Return a Point.*/
Point::Point(unsigned int dim){
    this->n = dim;
    for(unsigned int i = 0; i < n; ++i)
        this->points[i] = 0.;
}

/*Copy Constructor*/
Point::Point(Point &p):
n(p.n), points(p.points)
{}

// get and set function and other utility as print

/*setPoints modified EACH component of this->points
by passing by reference a std::vector<douyble>*/
void Point::setPoints(const std::vector<double> &v){
    if(n != v.size()){
        std::cout << "Vectors have different sizes!!!"<<std::endl;
        return;
    }
    for(size_t i = 0; i < n; ++i)
        points[i] = v[i];
}

/*setPoint modified ONE component of this->points
by passing by reference a double and the relative position
of the point we want to modify*/
void Point::setPoint(const double &v, size_t &k){
    if(k >= n){
        std::cout << "Vectors have different sizes!!!"<<std::endl;
        return;
    }
    points[k] = v;
}


const std::vector<double> Point::getPoints(){
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


/*norm(): computes the EUCLIDEAN NORM of a Point.
          Returns a double.*/
double Point::norm(){
    double sum = 0.;

    for(size_t i = 0; i < this->getN(); ++i)
        sum += this->getPoints()[i]*this->getPoints()[i];
    return sqrt(sum);
}


/*This function evaluate the distance of 2 Points
using */
double Point::distance(Point &p1, Point &p2){
    
    return (p1 - p2).norm();
    
}

/*In this section you will find some overloading operation
specifically made for the GD purpose*/

Point operator-(Point &a, Point &b)
{
    if(a.getN() != b.getN()){
        std::cerr<< "Sizes are different.\nCannot perform difference operation."<<std::endl;
        return Point(0);
    }

    std::vector<double> aux;
    for(size_t i = 0; i < a.getN(); ++i){
        aux.emplace_back(a.getPoints()[i] - b.getPoints()[i]);
    }
    return Point(a.getN(),aux);
}

Point operator*(double &a, Point &p){
    std::vector<double> aux;
    for(size_t i = 0; i < p.getN(); ++i){
        aux.emplace_back(a*p.getPoints()[i]);
    }
    return Point(p.getN(),aux);
}