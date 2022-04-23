#include "RegulatorBB.hpp"

float RegulatorBB::steer(float given_temperature_, float dt_, Room* room_, Heater* heater_) {
	measured_temperature = room_->get_temperature();

	if (measured_temperature < given_temperature_) {
		heater_->set_power_level(1);
		regulator_power = heater_->get_power_level() * heater_->get_nominal_power();
		room_->add_heat(regulator_power);
		return regulator_power;
	}
	else {
		heater_->set_power_level(0);
		regulator_power = heater_->get_power_level() * heater_->get_nominal_power();
		room_->add_heat(regulator_power);
		return regulator_power;
	}
}