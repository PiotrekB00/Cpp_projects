#pragma once

class Room {
public:
	Room(float wysokosc, float szerokosc, float glebokosc);
	float get_temperature() const { return temperaturaWewnetrzna; }
	float get_heat_in() const { return cieploWchodzace; }
	void add_heat(float cieplo);
	void update(float timeStep = 1.0);

private:
	float wysokosc;
	float szerokosc;
	float glebokosc;
	float powierzchniaScian;
	float masaPowietrza;
	float temperaturaWewnetrzna;
	float cieploWchodzace;
	const float cieploWlasciwe;
	const float gestoscPowietrza;
	const float gruboscScian;
	const float przewodnoscScian;
	const float temperaturaZewnetrzna;

	float heat_loss() const;
	float temperature_change(float cieplo, float czas = 1.0) const;
};
