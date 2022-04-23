#include "schedule.hpp"

Schedule::Schedule()
	:time_table(nullptr)
	,time_numbers(0)
{}

Schedule::~Schedule(){
	delete[] time_table;
}

Schedule::Schedule(const Schedule& _schedule) {
	time_numbers = _schedule.time_numbers;
	time_table = new Time[time_numbers];

	for (int i = 0; i < time_numbers; i++) {
		time_table[i] = _schedule.time_table[i];
	}
}

Schedule& Schedule::operator=(const Schedule& _schedule) {
	if (&_schedule == this) return *this;

	delete[] time_table;
	time_numbers = _schedule.time_numbers;
	time_table = new Time[time_numbers];
	for (int i = 0; i < time_numbers; i++) {
		time_table[i] = _schedule.time_table[i];
	}

	return *this;
}

void Schedule::add_time(Time& _time) {
	if (time_table == nullptr) {
		time_table = new Time[++time_numbers];
		time_table[0] = _time;
	}
	else if (time_table != nullptr) {
		Time* next_time = new Time[time_numbers + 1];
		for (int i = 0; i < time_numbers; i++) {
			next_time[i] = time_table[i];
		}
		next_time[time_numbers] = _time;
		delete[] time_table;

		time_table = next_time;
		time_numbers++;
	}
}

void Schedule::return_numbers_of_time() {
	std::cout << "Number of times: " << time_numbers << std::endl;
}

void Schedule::return_time(int _n) {
	time_table[_n - 1].display_time();
}

Time Schedule::sum_times(Time& _time) {
	for (int i = 0; i < time_numbers; i++) {
		_time = _time + time_table[i];
	}

	return _time;
}

void Schedule::display_schedule() {
	for (int i = 0; i < time_numbers; i++) {
		std::cout << i + 1 << " - ";
		time_table[i].display_time();
	}
}

Schedule Schedule::copy_to_range(const Time& _time) {
	Schedule _schedule;
	Time tmp_time;

	for (int i = 0; i < time_numbers; i++) {
		tmp_time = tmp_time + time_table[i];
		if (tmp_time < _time) {
			_schedule.add_time(time_table[i]);
			
		}
		else break;
	}

	return _schedule;
}
void Schedule::set_time_numbers(int _time_numbers) { 
	time_numbers = _time_numbers; 
}