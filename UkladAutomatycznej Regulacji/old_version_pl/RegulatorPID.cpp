#include "RegulatorPID.h"
#include <concepts>
RegulatorPID::RegulatorPID()
	: kp(4.0)
	, ki(0.02)
	, kd(0.1)
	, e(0)
	, e_integral(0)
	, e_delta(0)
	, e_prev(0)
	, aktualna_moc_PID(0)
{}

float RegulatorPID::steruj(float zadana_temperatura, /*float zmierzona_temperatura, */float delta_t, Pomieszczenie* pomieszczenie, Grzejnik grzejnik) {
	float zmierzona_temperatura;
	float temp;

	try {
		zmierzona_temperatura = pomieszczenie->getTemperatura();
		e = zadana_temperatura - zmierzona_temperatura;
		//std::cout << "zadana_temperatura: " << zadana_temperatura << std::endl;
		//std::cout << "zmierzona_temperatura: " << zmierzona_temperatura << std::endl;
		//std::cout << "e: " << e << std::endl;
		temp = czesc_proporcjonalna(e) + czesc_calkujaca(e, delta_t) + czesc_rozniczkujaca(e, delta_t);
		//std::cout << "czesc proporcjonalna: " << czesc_proporcjonalna(e) << std::endl;
		//std::cout << "czesc calkujaca: " << czesc_calkujaca(e, delta_t) << std::endl;
		//std::cout << "czesc rozniczukaca: " << czesc_rozniczkujaca(e, delta_t) << std::endl;
		//std::cout << "suma: " << temp << std::endl;
		grzejnik.ustaw_poziom_mocy(temp);
	}
	catch (const char* komunikat_wyjatek) {
		std::cout << komunikat_wyjatek << std::endl;
	}
	
	aktualna_moc_PID = grzejnik.akcesor_akt_poziom_mocy() * grzejnik.akcesor_moc_nominalna();
	pomieszczenie->dodajCieplo(aktualna_moc_PID);

	return aktualna_moc_PID;

}

float RegulatorPID::czesc_proporcjonalna(float e) {
	return kp * e;
}

float RegulatorPID::czesc_calkujaca(float e, float delta_t) {
	e_integral += e * delta_t;
	return kd * e_integral;
}

float RegulatorPID::czesc_rozniczkujaca(float e, float delta_t) {
	float tmp;
	try {
		if (e_prev == 0) {
			e_prev = e;
			e_delta = e / delta_t;
			return kd * e_delta;
		}
		else {
			e_delta = (e - e_prev) / delta_t;
			tmp = e_delta;
			e = e_prev;
			return kd * tmp;
		}
	}
	catch (const char* komunikat_wyjatek) {
		std::cout << komunikat_wyjatek << std::endl;
	}
}