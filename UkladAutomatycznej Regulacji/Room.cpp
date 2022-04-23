#include "Room.hpp"

Room::Room(float wys_, float szer_, float gleb_)
    : wysokosc(wys_)           // m
    , szerokosc(szer_)         // m
    , glebokosc(gleb_)         // m
    , cieploWchodzace(0)       // W
    , cieploWlasciwe(721)      // J/kg * degC
    , gestoscPowietrza(1.225)  // kg/m3
    , gruboscScian(0.4)        // m
    , przewodnoscScian(0.3)    // W / (m*degC)
    , temperaturaZewnetrzna(-20.0) // degC
    , temperaturaWewnetrzna(20.0)  // degC
{
    powierzchniaScian = 2 * (szerokosc + glebokosc) * wysokosc;
    masaPowietrza = szerokosc * glebokosc * wysokosc * gestoscPowietrza;
}

void Room::update(float dt) {
    /*Oblicza nowa temperature w pomieszczeniu na podstawie wplywajacego ciepla.*/
    cieploWchodzace -= heat_loss();
    temperaturaWewnetrzna += temperature_change(cieploWchodzace, dt);
    cieploWchodzace = 0.0;
}

void Room::add_heat(float q) {
    /*Dodaje pewna ilosc ciepla (w watach) wplywajaca do pomieszczenia.*/
    cieploWchodzace += q;
}

float Room::heat_loss() const {
    /*Uproszczony model przeplywu ciepla przez sciane o podanych parametrach.*/
    float tempGradient = (temperaturaWewnetrzna - temperaturaZewnetrzna) / gruboscScian;
    float cieplo = przewodnoscScian * powierzchniaScian * tempGradient;
    return cieplo;
}

float Room::temperature_change(float q, float dt) const {
    /*Oblicza zmiane temperatury osrodka na podstawie jego parametrow i wplywajacego ciepla.
      q = m*c*dt  =>  dtemp = q/(m*c)
    */
    return q / (masaPowietrza * cieploWlasciwe) * dt;
}