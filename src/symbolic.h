#ifndef PROJECT_TEST_SRC_SYMBOLIC_HEADER
#define PROJECT_TEST_SRC_SYMBOLIC_HEADER

#include <unordered_map>
#include <ostream>
#include <string>

namespace sym
{

class ABSExpr;
typedef std::unordered_map<std::string, ABSExpr*> Context;

class ABSExpr
{
public:
    virtual double full_eval(const Context&) = 0;
    virtual ABSExpr* partial_eval(const Context&) = 0;
    virtual std::ostream& gen(std::ostream&) = 0;
    virtual ABSExpr* derivate(const std::string&) = 0;
};

class Placeholder: public ABSExpr
{
public:
    Placeholder(const std::string& name) noexcept:
        _name(name)
    {}

    double full_eval(const Context&) override;
    ABSExpr* partial_eval(const Context&) override;
    std::ostream& gen(std::ostream&) override;
    ABSExpr* derivate(const std::string&) override;

private:
    std::string _name;
};

class Scalar: public ABSExpr
{
public:
    Scalar(double v) noexcept:
        _value(v)
    {}

    double full_eval(const Context&) override;
    ABSExpr* partial_eval(const Context&) override;
    std::ostream& gen(std::ostream&) override;
    ABSExpr* derivate(const std::string&) override;

private:
    double _value;
};

class Add: public ABSExpr
{
public:
    Add( ABSExpr* a,  ABSExpr* b) noexcept:
        _lhs(a), _rhs(b)
    {}

    ~Add(){
        delete _lhs;
        delete _rhs;
    }

    double full_eval(const Context&) override;
    ABSExpr* partial_eval(const Context&) override;
    std::ostream& gen(std::ostream&) override;
    ABSExpr* derivate(const std::string&) override;

private:
    ABSExpr* _lhs;
    ABSExpr* _rhs;
};

class Mult: public ABSExpr
{
public:
    Mult( ABSExpr* a,  ABSExpr* b) noexcept:
        _lhs(a), _rhs(b)
    {}

    ~Mult(){
        delete _lhs;
        delete _rhs;
    }

    double full_eval(const Context&) override;
    ABSExpr* partial_eval(const Context&) override;
    std::ostream& gen(std::ostream&) override;
    ABSExpr* derivate(const std::string&) override;

private:
    ABSExpr* _lhs;
    ABSExpr* _rhs;
};


ABSExpr* make_var(const std::string& name);
ABSExpr* make_val(double v);
ABSExpr* mult(ABSExpr* l , ABSExpr* r);
ABSExpr* add(ABSExpr* l , ABSExpr* r);
void print(ABSExpr* f);

}

#endif
