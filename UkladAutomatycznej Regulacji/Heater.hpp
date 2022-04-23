#pragma once

class Heater {
public:
	Heater();
	
	void set_nominal_power(float nominal_power_);
	void set_power_level(float power_level_);

	float get_nominal_power() { return nominal_power; }
	float get_power_level() { return power_level; }

private:
	float nominal_power; //in W
	float power_level; //in %
};