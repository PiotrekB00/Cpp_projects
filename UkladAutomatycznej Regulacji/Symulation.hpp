#pragma once
#include "Room.hpp"
#include "Heater.hpp"
#include "Regulator.hpp"
#include <iostream>
#include <vector>
#include <fstream>

class Symulation {
public:
	Symulation();// = default;
	Symulation(const Symulation& symulation_) = delete;
	Symulation& operator=(const Symulation& symulation_) = delete;
	~Symulation();

	void iteration(float current_time_);
	void process(int iterations_, float dt_);
	void save_to_csv();

	void run();
	void set_dt(float dt_);
	void set_iterantions(int iterations_);
	void set_room(float height_, float width_, float depth_);
	void set_given_temperature(float given_temperature_);

private:
	Room* room;
	Heater* heater;
	Regulator* regulator;

	float dt;
	float current_time;
	float current_power;
	int iterations;
	float height;
	float width;
	float depth;
	float given_temperature;

	std::vector<float> temperature_container;
	std::vector<float> time_container;
	std::vector<float> power_container;
};