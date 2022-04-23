#pragma once
#include <iostream>

class Czas {
private:
	int sekundy;
	int minuty;
	int godziny;

public:
	int pokazSekundy();
	int pokazMinuty();
	int pokazGodziny();

	void wprowadzCzas(int s = 0, int m = 0, int h = 0);
	void wyswietl();
	Czas operator+(Czas& _czas);
	Czas operator+(int _sek);
	bool operator<(Czas& _czas);
	bool operator==(Czas& _czas);
	
	Czas();
	Czas(int s, int m, int h);
	Czas(int s, int m);
	Czas(int s);
	~Czas();
	

};