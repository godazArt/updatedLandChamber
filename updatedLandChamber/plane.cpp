#include "plane.h"


int Plane::idGen{ 0 };

double Plane::squareSolver()
{
    return sides[0] * sides[0];
}


Plane::Plane(std::vector<double> sides)
{
    this->sides = sides;
    id = idGen++;
}

double Plane::getS()
{
    return S; 
}

void Plane::addHolder(Holder& per)
{
    m_holders.push_back(per);
    per.addLand(*this);
}

double Square::squareSolver()
{
    return pow(sides[0], 2);
}

Square::Square(std::vector<double> sides) : Plane{sides}
{
    S = squareSolver();
}

double Circle::squareSolver()
{
    return pow(sides[0], 2) * M_PI;
}

Circle::Circle(std::vector<double> sides) : Plane{ sides }
{
    S = squareSolver();
}

double Rectangle::squareSolver()
{
    return sides[0] * sides[1];
}

Rectangle::Rectangle(std::vector<double> sides) :Plane{ sides }
{
    S = squareSolver();
}

double Triangle::squareSolver()
{
    double p{ 0 };
    for (int i = 0; i < sides.size(); ++i)
        p += sides[i] / 2;
    return sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
}

Triangle::Triangle(std::vector<double> sides) :Plane{ sides }
{
    S = squareSolver();
}
