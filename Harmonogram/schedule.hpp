#pragma once
#include <iostream>
#include "time.hpp"

class Schedule {
public:
	Schedule();
	~Schedule();
	Schedule(const Schedule& _schedule);
	Schedule& operator=(const Schedule& _schedule);
	
	void set_time_numbers(int _time_numbers);
	void display_schedule();
	void add_time(Time& _time);
	void return_numbers_of_time();
	void return_time(int _n);
	Time sum_times(Time& _time);
	Schedule copy_to_range(const Time& _time);
	int get_time_numbers() { return time_numbers; }
private:
	Time* time_table;
	int time_numbers;
};

