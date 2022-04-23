#include "Heater.hpp"

Heater::Heater() : nominal_power(0), power_level(0) {}

void Heater::set_nominal_power(float nominal_power_) {
	nominal_power = nominal_power_;
}

void Heater::set_power_level(float power_level_) {
	if (power_level_ < 0) {
		power_level = 0;
	}
	else if (power_level_ > 1) {
		power_level = 1;
	}
	else {
		power_level = power_level_;
	}
}