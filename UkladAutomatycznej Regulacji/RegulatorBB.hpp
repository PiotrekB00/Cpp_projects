#pragma once
#include "Regulator.hpp"

class RegulatorBB : public Regulator {
public:
	float steer(float given_temperature_, float dt_, Room* room_, Heater* heater_);
};