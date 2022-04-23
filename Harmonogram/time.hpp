#pragma once
#include <iostream>

class Time {
public:
	Time(); 
	Time(int _seconds);
	Time(int _seconds, int _minutes);
	Time(int _seconds, int _minutes, int _hours);
	~Time() {};

	Time operator+(Time& _time);
	Time operator+(int _seconds);
	bool operator==(const Time& _time);
	bool operator<(const Time& _time);

	void display_time();
	void set_time(int _seconds, int _minutes, int _hours);
	void enter_time(Time& _time);
private:
	int seconds;
	int minutes;
	int hours;

	void calculate_time();
	int get_seconds() { return seconds; }
	int get_minutes() { return minutes; }
	int get_hours() { return hours; }
};