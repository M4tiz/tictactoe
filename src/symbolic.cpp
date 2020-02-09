#include "symbolic.h"
#include <iostream>

namespace sym{

double Placeholder::full_eval(const Context& c)     { return c.at(_name)->full_eval(c); }
ABSExpr* Placeholder::partial_eval(const Context& c){ return c.count(_name) == 0 ? this : c.at(_name); }
std::ostream& Placeholder::gen(std::ostream& out)   { return out << _name;}
ABSExpr* Placeholder::derivate(const std::string& n){ return n == _name ? new Scalar(1): new Scalar(0); }

double Scalar::full_eval(const Context&)        {   return _value; }
ABSExpr* Scalar::partial_eval(const Context&)   {   return this; }
std::ostream& Scalar::gen(std::ostream& out)    {   return out << _value; }
ABSExpr* Scalar::derivate(const std::string&)   {   return new Scalar(0); }

double Add::full_eval(const Context& c)         {   return _lhs->full_eval(c) + _rhs->full_eval(c); }
ABSExpr* Add::partial_eval(const Context& c)    {   return new Add(_lhs->partial_eval(c), _rhs->partial_eval(c));}
std::ostream& Add::gen(std::ostream& out)       {   out << "("; _lhs->gen(out) << " + "; _rhs->gen(out) << ")"; return out;}
ABSExpr* Add::derivate(const std::string& c)    {   return new Add(_lhs->derivate(c), _rhs->derivate(c));}

double Mult::full_eval(const Context& c)        {   return _lhs->full_eval(c) * _rhs->full_eval(c); }
ABSExpr* Mult::partial_eval(const Context& c)   {   return new Mult(_lhs->partial_eval(c), _rhs->partial_eval(c));}
std::ostream& Mult::gen(std::ostream& out)      {   out << "("; _lhs->gen(out) << " * "; _rhs->gen(out) << ")"; return out;}

ABSExpr* Mult::derivate(const std::string& c)   {
    auto a = new Mult(_lhs->derivate(c), _rhs);
    auto b = new Mult(_lhs, _rhs->derivate(c));
    return new Add(a, b);
}

ABSExpr* make_var(const std::string& name) {   return new Placeholder(name);   }
ABSExpr* make_val(double v)                {   return new Scalar(v);   }
ABSExpr* mult(ABSExpr* l , ABSExpr* r)     {   return new Mult(l, r);  }
ABSExpr* add(ABSExpr* l , ABSExpr* r)      {   return new Add(l, r);   }

void print(ABSExpr* f) { f->gen(std::cout) << std::endl; }
}
