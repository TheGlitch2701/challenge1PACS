#include "mpParser.h"
#include "Point.hpp"

#include <memory>
#include <string>

class MuparserXFun
{
public:
  /*MuparserXFun(const MuparserXFun &m)
    : m_parser(m.m_parser), m_vars(m.m_vars)
  {
    unsigned int n = m.getM_vars().getPoints().size();
    mup::Value arr1[n];
    std::string aux = "";

    for(size_t i = 0; i < n; ++i){
      arr1[i] = (mup::float_type) m.getM_vars().getPoints()[i];

      aux = "x" + std::to_string(i);

      m_parser.DefineVar(_T(aux), mup::Variable(&arr1[i]));
    }
  };*/

  MuparserXFun(const std::string &s, Point &p,const size_t &k)
  : m_k(k), m_s(s)
  {
    try
      {
      
      std::cout << "Inizia la funzione: " + s <<std::endl;

      size_t n = p.getPoints().size();

      }
    catch (mup::ParserError &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
  };

  double
  operator()(Point &p)
  {
    mup::Value m_arr(m_k,0.);
    for(size_t i = 0; i < m_k; ++i){
        m_arr.At(i) = p.getPoints()[i];
      }
    std::cout << "ok"<<std::endl;
    mup::Variable m_variable(&m_arr);

    m_parser.DefineVar("x", &m_variable);
      
    m_parser.SetExpr(m_s);

    std::cout << m_parser.Eval() << std::endl;
    return 0.;
  };

  /*Point getM_vars()const {
    return this->m_vars;
  }

  void setM_vars(Point &p){
    m_vars.setPoints(p.getPoints());
  }*/

private:
  const size_t      m_k;
  const std::string m_s;
  mup::ParserX      m_parser;
};
