#pragma once
#include "Heater.hpp"
#include "Room.hpp"

class Regulator {
public: 
	Regulator() :regulator_power(0), measured_temperature(0) {}
	virtual float steer(float given_temperature_, float dt_, Room* room_, Heater* heater_) = 0;

protected:
	float regulator_power;
	float measured_temperature;
};