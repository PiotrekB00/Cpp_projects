#pragma once
#include "Regulator.h"
#include "Grzejnik.h"
#include "Pomieszczenie.h"

class RegulatorPID :public Regulator {
private:
	float kp, ki, kd, e, e_integral, e_delta, e_prev;
	float aktualna_moc_PID;
public:
	RegulatorPID();
	//~RegulatorPID();

	float steruj(float zadana_temperatura, /*float zmierzona_temperatura, */float delta_t, Pomieszczenie* _pomieszczenie, Grzejnik _grzejnik);
	float czesc_proporcjonalna(float e);
	float czesc_calkujaca(float e, float delta_t);
	float czesc_rozniczkujaca(float e, float delta_t);
};