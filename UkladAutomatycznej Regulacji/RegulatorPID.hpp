#pragma once
#include "Regulator.hpp"

class RegulatorPID : public Regulator {
public:
	RegulatorPID();

	float steer(float given_temperature_, float dt_, Room* room_, Heater* heater_);
	float proportional_part(float e_);
	float integrating_part(float e_, float dt_);
	float derivative_part(float e_, float dt_);
	void set_pid(float kp_, float ki_, float kd);

private:
	float kp;
	float ki;
	float kd;
	float e;
	float e_integral;
	float e_previous;
};