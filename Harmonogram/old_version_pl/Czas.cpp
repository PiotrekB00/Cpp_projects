#include "Czas.h"
#include "Harmonogram.h"

Czas::Czas() 
{
	sekundy = 0;
	minuty = 0;
	godziny = 0;

}

Czas::Czas(int s, int m, int h)
	: sekundy(s)
	, minuty(m)
	, godziny(h)
{
	while (s >= 60) {
		m++;
		s = s - 60;
	}

	while (s < 0) {
		m--;
		s = s + 60;
	}

	while (m >= 60) {
		h++;
		m -= 60;
	}

	while (m < 0) {
		h--;
		m += 60;
	}
	godziny = h;
	minuty = m;
	sekundy = s;

}

Czas::Czas(int s, int m) 
	: sekundy(s)
	, minuty(m)
	, godziny(0)
{
	int h = 0;

	while (s >= 60) {
		m++;
		s = s - 60;
	}

	while (s < 0) {
		m--;
		s = s + 60;
	}

	while (m >= 60) {
		h++;
		m -= 60;
	}

	while (m < 0) {
		h--;
		m += 60;
	}
	godziny = h;
	minuty = m;
	sekundy = s;

}

Czas::Czas(int s) 
	: sekundy(s)
	, minuty(0)
	, godziny(0) 
{
	int h = 0;
	int m = 0;

	while (s >= 60) {
		m++;
		s = s - 60;
	}

	while (s < 0) {
		m--;
		s = s + 60;
	}

	while (m >= 60) {
		h++;
		m -= 60;
	}

	while (m < 0) {
		h--;
		m += 60;
	}
	godziny = h;
	minuty = m;
	sekundy = s;

}

Czas::~Czas() {

}


bool Czas::operator<(Czas& _czas) {
	Czas temp = _czas;

	if (godziny < temp.godziny) {
		return true;
	}
	else if ((godziny == temp.godziny) && (minuty < temp.minuty)) {
		return true;
	}
	else if ((godziny == temp.godziny) && (minuty == temp.minuty) && (sekundy < temp.sekundy)) {
		return true;
	}
	return false;

}

bool Czas::operator==(Czas& _czas) {
	Czas temp = _czas;

	if ((sekundy == temp.sekundy) && (minuty == temp.minuty) && (godziny == temp.godziny)) {
		return true;
	}
	else
		return false;

}

Czas Czas::operator+(int _sek) {
	Czas temp;
	temp.godziny = godziny;
	temp.minuty = minuty;
	temp.sekundy = sekundy + _sek;

	while (temp.sekundy >= 60) {
		temp.minuty++;
		temp.sekundy -= 60;
	}

	while (temp.sekundy < 0) {
		temp.minuty--;
		temp.sekundy += 60;
	}

	while (temp.minuty >= 60) {
		temp.godziny++;
		temp.minuty -= 60;
	}

	while (temp.minuty < 0) {
		temp.godziny--;
		temp.minuty += 60;
	}

	return temp;

}

Czas Czas::operator+(Czas& _czas) {
	Czas temp;
	godziny += _czas.godziny;
	minuty += _czas.minuty;
	sekundy += _czas.sekundy;

	while (sekundy >= 60) {
		minuty++;
		sekundy -= 60;
	}

	while (sekundy < 0) {
		minuty--;
		sekundy += 60;
	}

	while (minuty >= 60) {
		godziny++;
		minuty -= 60;
	}

	while (minuty < 0) {
		godziny--;
		minuty += 60;
	}
	return temp;
}

void Czas::wyswietl() {
	std::cout << "Czas " << pokazGodziny() << ":" << pokazMinuty() << ":" << pokazSekundy() << std::endl;
}

int Czas::pokazSekundy() {
	return sekundy;

}

int Czas::pokazMinuty() {
	return minuty;

}

int Czas::pokazGodziny() {
	return godziny;

}

void Czas::wprowadzCzas(int s, int m, int h) {
	while (s >= 60) {
		m++;
		s = s - 60;
	}

	while (s < 0) {
		m--;
		s = s + 60;
	}

	while (m >= 60) {
		h++;
		m = m - 60; //-=
	}

	while (m < 0) {
		h--;
		m = m + 60; //+=
	}

	godziny = h;
	minuty = m;
	sekundy = s;

}
