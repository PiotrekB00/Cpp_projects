#include "time.hpp"

Time::Time() {
	seconds = 0;
	minutes = 0;
	hours = 0;
}

Time::Time(int _seconds) 
	:seconds(_seconds)
	,minutes(0)
	,hours(0)
{
	calculate_time();
}

Time::Time(int _seconds, int _minutes) 
	: seconds(_seconds)
	, minutes(_minutes)
	, hours(0)
{
	calculate_time();
}

Time::Time(int _seconds, int _minutes, int _hours) 
	: seconds(_seconds)
	, minutes(_minutes)
	, hours(_hours)
{
	calculate_time();
}

void Time::display_time() {
	std::cout << "Time: "
		<< get_hours() << ":"
		<< get_minutes() << ":" 
		<< get_seconds() << std::endl;
}

void Time::calculate_time() {
	if (seconds >= 60) {
		minutes += seconds / 60;
		seconds = seconds % 60;

	}
	if (minutes >= 60) {
		hours += minutes / 60;
		minutes = minutes % 60;
	}
}

Time Time::operator+(Time& _time) {
	hours += _time.hours;
	minutes += _time.minutes;
	seconds += _time.seconds;
	calculate_time();

	return *this;
}
Time Time::operator+(int _seconds) {
	Time _time;
	_time.hours = hours;
	_time.minutes = minutes;
	_time.seconds = seconds + _seconds;

	if (_time.seconds >= 60) {
		_time.minutes += _time.seconds / 60;
		_time.seconds = _time.seconds % 60;

	}
	if (_time.minutes >= 60) {
		_time.hours += _time.minutes / 60;
		_time.minutes = _time.minutes % 60;
	}

	return _time;
}

bool Time::operator==(const Time& _time) {
	if (seconds == _time.seconds
		&& minutes == _time.minutes
		&& hours == _time.hours) {
		return true;
	}
	else {
		return false;
	}
}

bool Time::operator<(const Time& _time) {
	if (hours < _time.hours) {
		return true;
	}
	else if (hours == _time.hours
		&& minutes < _time.minutes) {
		return true;
	}
	else if (hours == _time.hours
		&& minutes == _time.minutes
		&& seconds < _time.seconds) {
		return true;
	}
	else {
		return false;
	}
}

void Time::set_time(int _seconds, int _minutes, int _hours) {
	hours = _hours;
	minutes = _minutes;
	seconds = _seconds;
	calculate_time();
}

void Time::enter_time(Time& _time) {
	unsigned int s, m, h;

	do {
		while (1) {
			system("cls");
			std::cout << "enter seconds ";
			std::cin >> s;
			std::cout << "enter minutes ";
			std::cin >> m;
			std::cout << "entes hours ";
			std::cin >> h;
			if (std::cin.fail() == true) {
				std::cin.clear();
				std::cin.ignore(256, '\n');
			}
			else break;
		}
	} while ((s <= 0) && (m <= 0) && (h <= 0));//sth wrong

	_time.set_time(s, m, h);
}
