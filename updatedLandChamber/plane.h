#pragma once
#include "person.h"
#include <vector>
#include <functional>
#include <string>
#include <vector>


class Holder;

class Plane
{
    
protected:    
    int id;
    static int idGen;
    double S;    
    std::vector<double> sides;
    std::vector<std::reference_wrapper<const Holder>> m_holders{};
    virtual double squareSolver();

public:
    Plane(std::vector<double> sides);
    void addHolder(Holder& per);
    double getS() ;
};

class Square : public Plane
{
    virtual double squareSolver();
public:
    Square(std::vector<double> sides);
};

class Circle :public Plane
{
    virtual double squareSolver();
public:
    Circle(std::vector<double> sides);
};

class Rectangle :public Plane
{
    virtual double squareSolver();
public:
    Rectangle(std::vector<double> sides);
};

class Triangle : public Plane
{
    virtual double squareSolver();
public:
    Triangle(std::vector<double> sides);
};