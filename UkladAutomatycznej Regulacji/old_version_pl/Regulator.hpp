#pragma once
#include "Grzejnik.h"
#include "Pomieszczenie.h"
#include <iostream>


class Regulator {
protected:
	Grzejnik *grzejnik;
	Pomieszczenie* pomieszczenie;

	float zadanaTemperatura;

public:
	virtual float steruj(float zadana_temperatura, /*float zmierzona_temperatura, */float delta_t, Pomieszczenie* _pomieszczenie, Grzejnik _grzejnik) = 0;

};