#pragma once
#include "Regulator.h"
#include "Grzejnik.h"
#include "Pomieszczenie.h"

class RegulatorBB :public Regulator {
private:
	float aktualna_moc_BB;
	float zmierzona_temperatura;
public:
	RegulatorBB();
	~RegulatorBB();

	float steruj(float zadana_temperatura, /*float zmierzona_temperatura, */float delta_t, Pomieszczenie* _pomieszczenie, Grzejnik _grzejnik);

};