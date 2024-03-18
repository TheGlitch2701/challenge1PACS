#include "mpParser.h"
#include "Point.hpp"

#ifndef MUPARSERX_FUN_HPP_
#define MUPARSERX_FUN_HPP_

#include <string>

class MuparserXFun
{
public:
  MuparserXFun(const MuparserXFun &m)
  : m_parser(m.m_parser), m_s(m.m_s), m_k(m.m_k)
  {};

  MuparserXFun(const std::string &s, Point &p,const size_t &k)
  : m_k(k), m_s(s)
  {
    try
      {
      
      }
    catch (mup::ParserError &e)
      {
        std::cerr << e.GetMsg() << std::endl;
      }
  };

  double operator()(Point &p)
  {
    mup::Value result;
    
    mup::Value m_arr(m_k,0.);
    
    for(size_t i = 0; i < m_k; ++i){
        m_arr.At(i) = p.getPoints()[i];
      }
    
    mup::Variable m_variable(&m_arr);

    if(!this->flag){
      //std::cout << "Prima di Var" << std::endl;
      m_parser.DefineVar("x", &m_variable);
      //std::cout << "Prima di expr" << std::endl;
      m_parser.SetExpr(m_s);
      this->flag = true;
    }
    
    //std::cout << "Prima di Eval" <<std::endl;
    result = m_parser.Eval();

    return result;
  };

private:
  const size_t      m_k;
  const std::string m_s;
  mup::ParserX      m_parser;
  bool              flag = false;
};

#endif