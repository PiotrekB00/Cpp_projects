#include "Symulation.hpp"
#include "RegulatorBB.hpp"
#include "RegulatorPID.hpp"

Symulation::Symulation()
	: dt(0)
	, current_time(0)
	, current_power(0)
	, iterations(0)
	, height(0)
	, width(0)
	, depth(0)
	, given_temperature(0)
	, room(nullptr)
	, heater(nullptr)
	, regulator(nullptr)
{
	heater = new Heater();
}
Symulation::~Symulation() {
	delete[] room;
	delete[] heater;
	//delete regulator;
}

void Symulation::process(int iterantions_, float dt_) {
	for (int i = 0; i < iterantions_; i++) {
		current_time += dt_;
		iteration(current_time);
		std::cout << "STEP: " << i + 1 << std::endl;
		std::cout << "temp: " << temperature_container.at(i) << std::endl;
		std::cout << "time: " << time_container.at(i) << std::endl;
		std::cout << "power: " << power_container.at(i) << std::endl << std::endl;
	}
}

void Symulation::iteration(float current_time_) {
	//TEMPERATURE OPERATIONS
	temperature_container.push_back(room->get_temperature());

	//POWER OPERATIONS
	current_power = regulator->steer(given_temperature, current_time_, room, heater);
	power_container.push_back(current_power);

	//TIME OPERATIONS
	room->update(current_time_);
	time_container.push_back(current_time_);
}

void Symulation::save_to_csv() {
	std::fstream plik;
	std::locale pol("pl_PL");
	plik.imbue(pol);
	plik.open("results.csv", std::fstream::out);
	plik << "Temperature" << ";" << "Time" << ";" << "Power" << ";" << std::endl;
	plik << "[degC]" << ";" << "[s]" << ";" << "[W]" << ";" << std::endl;
	for (int i = 0; i < iterations; i++) {
		plik << temperature_container.at(i) << ";" << time_container.at(i) << ";" << power_container.at(i) << std::endl;
	}
	plik.close();
}

void Symulation::run() {
	int choose = 0;

	set_dt(0.5);
	set_iterantions(50);
	set_room(2, 3, 5);
	heater->set_nominal_power(1000);
	set_given_temperature(20);

	room = new Room(height, width, depth);
	RegulatorBB regulatorBB;
	RegulatorPID regulatorPID;

	do {
		while (1) {
			std::cout << "1-BB\n2-PID\n" << std::endl;
			std::cin >> choose;
			if (std::cin.fail() == true) {
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else break;
		}
	} while (choose != 1 && choose != 2);
	
	switch (choose) {
	case 1:
		system("cls");
		std::cout << "Simulation for BB regulator\n" << std::endl;
		//std::cout << "BB\n" << std::endl;
		regulator = &regulatorBB;
		process(iterations, dt);
		save_to_csv();
		std::cout << "\nSimulation end" << std::endl;
		system("pause");
		break;
	case 2:
		system("cls");
		std::cout << "Simulation for PID regulator\n" << std::endl;
		//std::cout << "PID\n" << std::endl;
		regulator = &regulatorPID;
		process(iterations, dt);
		save_to_csv();
		std::cout << "\nSimulation end" << std::endl;
		system("pause");
		break;
	}
}

void Symulation::set_dt(float dt_) {
	dt = dt_;
}

void Symulation::set_iterantions(int iterations_) {
	iterations = iterations_;
}

void Symulation::set_room(float height_, float width_, float depth_) {
	height = height_;
	width = width_;
	depth = depth_;
}

void Symulation::set_given_temperature(float given_temperature_) {
	given_temperature = given_temperature_;
 }

