#include "landChamber.h"
#include <iostream>


int LandChamber::landCount{ 0 };
int LandChamber::holderCount{ 0 };

double LandChamber::getSFromTo(int startId, int endId)
{
    double sum = 0;
    if (startId < 0)
        startId = 0;
    if (endId > landCount)
        endId = landCount;
    for (int i = startId; i < endId; ++i)
        sum += m_land[i]->getS();    
    return sum;
}

void LandChamber::addLand(int landType, std::vector<double> sides)
{
    Plane* land = nullptr;

    switch (landType)
    {
    case 0:
         land = new Square(sides);
        break;
    case 1:
        land = new Circle(sides);
        break;
    case 2:
        land = new Rectangle(sides);
        break;
    case 3:
        land = new Triangle(sides);
        break;
    default:
        land = new Plane(sides);
        break;
    }

    m_land.push_back(land);
    ++landCount;
    S += m_land.back()->getS();
}

void LandChamber::addHolder(std::string name)
{
    m_holder.push_back(name);
    ++holderCount;
}

void LandChamber::addHolder(Person newHolder)
{
    m_holder.push_back(newHolder.getName());
    ++holderCount;
}

void LandChamber::addHolderToLand(int landId, int holderId)
{
    if (landId >= landCount || landId < 0)
    {
        std::cout << "Id of land is not in range\n";
        return;
    }
    if (holderId >= holderCount || landId < 0)
    {
        std::cout << "Id of land is not in range\n";
        return;
    }
    m_land[landId]->addHolder(m_holder[holderId]);
}
