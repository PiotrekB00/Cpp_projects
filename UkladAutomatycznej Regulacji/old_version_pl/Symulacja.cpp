#include "Symulacja.h"

Symulacja::Symulacja()
	: pomieszczenie(nullptr)
	//stale
	, delta_t(0.5)
	, liczba_iteracji(24)
	, zadana_temperatura (20)
	, aktualny_czas(0)
	, aktualna_moc(0)
	, moc_nomin(1000.0)
	, moc_poziom(0.0)
	//zmienne wybieralne
	, w(2)
	, s(3)
	, g(5)
	, reg_bb(true)
	, dane(true)
{}

Symulacja::~Symulacja() {
	delete[] pomieszczenie;

}

void Symulacja::wpisywanie_danych() {
	//wybor wymiarow pokoju
	do {
		while (1) {
			std::cout << "Podaj wysokosc pokoju od 0 do 5" << std::endl;
			std::cin >> w;
			system("cls");
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			}
			else break;
		} 
	} while (w <= 0 || w >= 5);

	do {
		while (1) {
			std::cout << "Podaj szerokosc pokoju od 0 do 15" << std::endl;
			std::cin >> s;
			system("cls");
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			}
			else break;
		} 
	} while (s <= 0 || s >= 15);

	do {
		while (1) {
			std::cout << "Podaj glebokosc pokoju od 0 do 15" << std::endl;
			std::cin >> g;
			system("cls");
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			}
			else break;
		}
	} while (g <= 0 || g >= 15);
	//std::cout << "w: " << w << std::endl << "s: " << s << std::endl << "g: " << g << std::endl;
	
	//wybor temperatury
	do {
		while (1) {
			std::cout << "Ustaw temperature od 0 do 25" << std::endl;
			std::cin >> zadana_temperatura;
			system("cls");
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			}
			else break;
		} 
	} while (zadana_temperatura <= 0 || zadana_temperatura >= 25);
	//std::cout << "temperatura:" << zadana_temperatura << std::endl;

}

void Symulacja::start() {
	wybor_czy_dane();
	if (dane == false) {
		wpisywanie_danych();
	}

	pomieszczenie = new Pomieszczenie(w, s, g);

	regulator_bb = RegulatorBB();
	regulator_pid = RegulatorPID();

	grzejnik.ustaw_moc_nominalna(moc_nomin);
	grzejnik.ustaw_poziom_mocy(moc_poziom);

	wybor_regulatora();

	przebieg(liczba_iteracji, delta_t);
	Zapisz_do_csv();
}

void Symulacja::wybor_czy_dane() {
	int y;

	do {
		while (1) {
			std::cout << "Wybierz tryb" << std::endl << "1 - Przykladowe dane" << std::endl << "2 - Wybor danych (wymiary pomieszczenia i temperatury)" << std::endl;
			std::cin >> y;
			system("cls");
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			}
			else break;
		}

	} while ((y != 1) && (y != 2));
	switch (y) {
	case 1:
		dane = true; // dane z konsktruktora
		//std::cout << "zadane" << std::endl;
		break;
	case 2:
		dane = false; //dane z wpisywanie_danych()
		//std::cout << "wybierane" << std::endl;
		break;
	}
}

void Symulacja::wybor_regulatora() {
	int x;

	do {
		while (1) {
		std::cout << "Wybierz regulator" << std::endl << "1 - RegulatorBB" << std::endl << "2 - RegulatorPID" << std::endl;
		std::cin >> x;
		system("cls");
		if (std::cin.fail() == true) { //wykrycie b³êdu
			std::cin.clear(); //resetowanie flag b³êdu
			std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
		}
		else break;
		}

	} while ((x != 1) && (x != 2));
	switch (x) {
	case 1:
		reg_bb = true; // reg BB
		std::cout << "regBB" << std::endl;
		break;
	case 2:		
		reg_bb = false; //reg PID
		std::cout << "regPID" << std::endl;
		break;
	}
}

void Symulacja::iteracja(float delta_t) {
	if (reg_bb == true) {
		kontrola_mocy_BB();
	}
	else {
		kontrola_mocy_PID();
	}

	aktualny_czas += delta_t;
	aktualna_moc = grzejnik.akcesor_akt_poziom_mocy() * grzejnik.akcesor_moc_nominalna();
	pomieszczenie->dodajCieplo(aktualna_moc);

	std::cout << "cieplo: " << pomieszczenie->getCieploWchodzace() << std::endl;

	pomieszczenie->aktualizuj(aktualny_czas);
	dodaj_do_wektora();
}
//zakomentowany kod - rozwiazanie do etapu 2. pkt. 4 (przed wprowadzeniem agregacji)
void Symulacja::kontrola_mocy_PID() {
	//float temp_moc;
	/*temp_moc*/ aktualna_moc = regulator_pid.steruj(zadana_temperatura, /*pomieszczenie->getTemperatura(), */delta_t, pomieszczenie, grzejnik);
	//grzejnik.ustaw_poziom_mocy(/*temp_moc*/ aktualna_moc);
	//std::cout << "moc PID: " << temp_moc << std::endl;
}

void Symulacja::kontrola_mocy_BB() {
	//float temp_moc;
	/*temp_moc*/ aktualna_moc = regulator_bb.steruj(zadana_temperatura, /*pomieszczenie->getTemperatura(), */delta_t, pomieszczenie, grzejnik);
	//grzejnik.ustaw_poziom_mocy(temp_moc);
	//akt_moc_wyjsciowa.push_back(/*temp_moc*/ aktualna_moc);

}

void Symulacja::dodaj_do_wektora() {
	temperatura.push_back(pomieszczenie->getTemperatura());
	akt_moc_wyjsciowa.push_back(aktualna_moc);
	akt_czas.push_back(aktualny_czas);
}

void Symulacja::przebieg(int liczba_iteracji, float delta_t) {
	for (int i = 0; i < liczba_iteracji; i++) {
		aktualny_czas += delta_t;
		if (reg_bb == true) {
			kontrola_mocy_BB();
		}
		else {
			kontrola_mocy_PID();
		}
		pomieszczenie->aktualizuj(aktualny_czas);
		dodaj_do_wektora();
		
		//iteracja(delta_t);
		std::cout << "cieplo: " << /*pomieszczenie->getCieploWchodzace()*/akt_moc_wyjsciowa[i] << std::endl << "temperatura: " << pomieszczenie->getTemperatura() << std::endl << "czas: " << akt_czas[i] << std::endl << std::endl;
	}
}

void Symulacja::Zapisz_do_csv() {
	std::fstream plik;
	setlocale(LC_CTYPE, "Polish");
	plik.open("wyniki.csv", std::fstream::out);
	plik <<"Temp"<<";"<< "Moc" << ";" << "Czas" << ";" << std::endl;
	for (int i = 0; i < temperatura.size(); i++) {
		plik << temperatura[i] << ";" << akt_moc_wyjsciowa[i] << ";" << akt_czas[i] << std::endl;
	}
	plik.close();

}