#pragma once
#include "plane.h"
#include "person.h"
#include <memory>


class Plane;
class Holder;

class LandChamber
{

	std::vector<Plane*> m_land;
	std::vector<Holder> m_holder;
	double S;
	static int landCount;
	static int holderCount;	
public:
	double getTotalS() { return S; };
	double getSFromTo(int startId = 0, int endId = landCount);
	int get_landCount() { return landCount; };
	int get_holderCount() { return holderCount; };
	void addLand(int LandType, std::vector<double> sides);
	void addHolder(std::string name);
	void addHolder(Person newHolder);
	void addHolderToLand(int landId, int holderId);
};