#include "RegulatorPID.hpp"
//#include <iostream>

RegulatorPID::RegulatorPID() :kp(0), ki(0), kd(0), e(0), e_integral(0), e_previous(0) { set_pid(4.0, 0.02, 0.1); }

float RegulatorPID::steer(float given_temperature_, float dt_, Room* room_, Heater* heater_) {
	measured_temperature = room_->get_temperature();
	e = given_temperature_ - measured_temperature;

	//std::cout << "e: " << e << std::endl
	//	<< "given temp: " << given_temperature_ << std::endl
	//	<< "measured temp: " << measured_temperature << std::endl;

	heater_->set_power_level(proportional_part(e) + integrating_part(e, dt_) + derivative_part(e, dt_));
	//std::cout << "power_level: " << heater_->get_power_level() << std::endl;
	regulator_power = heater_->get_nominal_power() * heater_->get_power_level();
	room_->add_heat(regulator_power);
	return regulator_power;
}

float RegulatorPID::proportional_part(float e_) {
	return kp* e_;
}

float RegulatorPID::integrating_part(float e_, float dt_) {
	e_integral += e * dt_;
	//std::cout << "e_integral: " << e_integral << std::endl;
	return ki * e_integral;
}

float RegulatorPID::derivative_part(float e_, float dt_) {
	float delta_e;

	delta_e = (e - e_previous) / dt_;
	e_previous = e;
	//std::cout << "delta_e: " << delta_e << std::endl;
	return kd * delta_e;
}

void RegulatorPID::set_pid(float kp_, float ki_, float kd_) {
	kp = kp_;
	ki = ki_;
	kd = kd_;
}