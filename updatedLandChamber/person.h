#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include "plane.h"
#include <string>
#include <functional>
#include <vector>

class Plane;

class Person
{
    std::string name;
public:
    Person();
    Person(std::string newName);
    std::string getName();
};

class Holder
{
    int id;
    static int idGen;
    Person baseInfo;
        
public:
    void addLand(const Plane& land);
    Holder(std::string name);
    std::vector<std::reference_wrapper<const Plane>> m_land{};
};