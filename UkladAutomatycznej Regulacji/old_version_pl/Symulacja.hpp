#pragma once
#include "Pomieszczenie.h"
#include "Grzejnik.h"
#include "Regulator.h"
#include "RegulatorBB.h"
#include "RegulatorPID.h"
#include <iostream>
#include <vector>
#include <fstream>


class Symulacja {
private:
	Pomieszczenie* pomieszczenie;
	Grzejnik grzejnik;
	RegulatorBB regulator_bb;
	RegulatorPID regulator_pid;

	int liczba_iteracji;

	float delta_t;
	float aktualny_czas;
	float aktualna_moc;

	float zadana_temperatura;
	float moc_nomin;
	float moc_poziom;

	float w;
	float s;
	float g;

	bool reg_bb;
	bool dane;

public:
	std::vector<float> temperatura;
	std::vector<float> akt_czas;
	std::vector<float> akt_moc_wyjsciowa;

	Symulacja();
	~Symulacja();
	Symulacja(const Symulacja& _sumulacja) = delete;
	Symulacja& operator=(const Symulacja& _symulacja) = delete;

	void start();
	void iteracja(float delta_t);
	void przebieg(int liczba_iteracji, float delta_t);
	void Zapisz_do_csv();
	void dodaj_do_wektora();
	void kontrola_mocy_BB();
	void kontrola_mocy_PID();
	void wpisywanie_danych();
	void wybor_regulatora();
	void wybor_czy_dane();

	float akcesor_aktualna_moc() { return aktualna_moc; }
};