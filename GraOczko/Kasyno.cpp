#include "Kasyno.h"

Kasyno::Kasyno() 
	: talia()
	, karta(nullptr)
	, akt_karta(0)
{
	

	Karta karta_tmp;
	int kolor = 0;
	int wartosc = 0;

	for (int i = 0; i < 52; i++) {
		if (wartosc == 13) {
			kolor++;
			wartosc = 0;
		}
		karta_tmp = Karta(kolor, wartosc);
		//*akcesor_talia(i) = karta_tmp;
		talia[i] = karta_tmp;
		wartosc++;
	}
}

Kasyno::~Kasyno() {
	delete[] karta;
	delete[] gracz_ludzki;
	delete[] gracz_komputerowy;
}

void Kasyno::rozgrywka() {
	int n = 2, f = 0;
	int wybor = 0;
	
	Potasuj();
	//pokaz_talie();

	//WYBOR GRACZY
	do {
		while (1) { //nieskoñczona pêtla
			system("cls");
			std::cout << "Podaj liczbe graczy od 1 do 3" << std::endl;
			std::cin >> n; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			}
			else break;
		}
	} while ((n != 1) && (n != 2) && (n != 3));

	//WYBOR BOTOW
	do {
		while (1) { //nieskoñczona pêtla
			system("cls");
			std::cout << "Podaj liczbe botow od 1 do 3" << std::endl;
			std::cin >> f; //pobranie zmiennej
			if (std::cin.fail() == true) { //wykrycie b³êdu
				std::cin.clear(); //resetowanie flag b³êdu
				std::cin.ignore(256, '\n'); //czyszczenie 256 znaków bufora
			}
			else break;
		}
	} while ((f != 1) && (f != 2) && (f != 3));

	gracz_ludzki = new Gracz[n];
	gracz_komputerowy = new Bot[f];
	/*gracz_ludzki = new Gracz[f+n];//gracz_ludzki = wszyscy gracze
	for (int i = f; i < f + n; i++) {
		gracz_ludzki[i] = Bot();
	}*/

	rozdawanie_kart(n, f);

	Podsumowanie(n, f);

	Zapisz_do(n, f);
}
void Kasyno::rozdawanie_kart(int n, int f) {
	int tmp = 0;
	setlocale(LC_CTYPE, "Polish");

	//2 pierwsze i nazywanie graczy i botow(i odwaga)
	for (int i = 0; i < n; i++) {
		gracz_ludzki[i].wezKarte(dajKarte());
		gracz_ludzki[i].wezKarte(dajKarte());
		gracz_ludzki[i].nazwij();
	}

	for (int i = 0; i < f; i++) {
		gracz_komputerowy[i].wezKarte(dajKarte());
		gracz_komputerowy[i].wezKarte(dajKarte());
		gracz_komputerowy[i].nazwij_bot(i);
		gracz_komputerowy[i].ustaw_odwage();
	}
	//dobieranie
	while (tmp < (n + f)) {
		system("cls");
		for (int i = 0; i < f; i++) {
			std::cout << gracz_komputerowy[i].akcesor_nazwa() << std::endl;
			gracz_komputerowy[i].pokaz();
			gracz_komputerowy[i].wybor_bot();//czy bot pasuje czy nie
			if ((gracz_komputerowy[i].decyzja_czy_dobieram == true) && (gracz_komputerowy[i].punkty < 21)) {
				system("cls");
				gracz_komputerowy[i].wezKarte(dajKarte());
			}
			else if (gracz_komputerowy[i].decyzja_czy_dobieram == false) {
				system("cls");
				tmp++;
			}
		}
		for (int i = 0; i < n; i++) {
			std::cout << gracz_ludzki[i].akcesor_nazwa() << std::endl;
			gracz_ludzki[i].pokaz();
			gracz_ludzki[i].wybor_pas();
			if ((gracz_ludzki[i].decyzja_czy_dobieram == true) && (gracz_ludzki[i].punkty < 21)) {
				system("cls");
				//std::cout << gracz[i].akcesor_nazwa() << " dobiera" << std::endl;
				gracz_ludzki[i].wezKarte(dajKarte());
				//gracz[i].pokaz();
			}
			else if (gracz_ludzki[i].decyzja_czy_dobieram == false) {
				system("cls");
				//std::cout << gracz_ludzki[i].akcesor_nazwa() << " pasuje" << std::endl << std::endl;
				tmp++;
			}
		}
	}
}

void Kasyno::Podsumowanie(int n, int f) {
	int tmp_pkt = 0;
	int tmp_zakres = 0;
	setlocale(LC_CTYPE, "Polish");
	system("cls");
	for (int i = 0; i < f; i++) {
		std::cout << gracz_komputerowy[i].akcesor_nazwa() << std::endl;
		gracz_komputerowy[i].pokaz();

		//jesli wszyscy maja wiecej niz 21 pkt tmp_pkt pozostaje rowne 0
		if ((gracz_komputerowy[i].punkty > tmp_pkt) && (gracz_komputerowy[i].punkty < 22)) {
			tmp_pkt = gracz_komputerowy[i].punkty;
			//gracz[i].pokaz_punkty();
		}
	}

	for (int i = 0; i < n; i++) {
		std::cout << gracz_ludzki[i].akcesor_nazwa() << std::endl;
		gracz_ludzki[i].pokaz();

		//jesli wszyscy maja wiecej niz 21 pkt tmp_pkt pozostaje rowne 0
		if ((gracz_ludzki[i].punkty > tmp_pkt) && (gracz_ludzki[i].punkty < 22)) {
			tmp_pkt = gracz_ludzki[i].punkty;
			//gracz[i].pokaz_punkty();
		}
	}

	//Decyzja kto wygral
	for (int i = 0; i < n; i++) {
		//gracz[i].pokaz_punkty();
		if (gracz_ludzki[i].punkty == tmp_pkt) {
			std::cout << std::endl << "Wygral " << gracz_ludzki[i].akcesor_nazwa() << " uzyskujac " << tmp_pkt << " punktow" << std::endl;
		}
		//gracz[i].pokaz_punkty();
	}
	for (int i = 0; i < f; i++) {
		if (gracz_komputerowy[i].punkty == tmp_pkt) {
			std::cout << std::endl << "Wygral " << gracz_komputerowy[i].akcesor_nazwa() << " uzyskujac " << tmp_pkt << " punktow" << std::endl;
		}
	}
	if (tmp_pkt == 0) {
		std::cout << std::endl << "Nikt nie wygral " << std::endl << std::endl;
	}
	std::cout << std::endl;
}

void Kasyno::Zapisz_do(int n, int f) {
	std::fstream plik;
	plik.open("wyniki.txt", std::fstream::out);
	plik << std::endl;
	for (int i = 0; i < n; i++) {
		plik.width(20);
		plik.setf(std::ios::left, std::ios::adjustfield);
		plik << gracz_ludzki[i].akcesor_nazwa();

		plik.width(20);
		plik.setf(std::ios::left, std::ios::adjustfield);
		plik << gracz_ludzki[i].pokaz_karty();

		plik.width(15);
		plik.setf(std::ios::right, std::ios::adjustfield);
		plik << gracz_ludzki[i].punkty << std::endl;
	}
	for (int i = 0; i < f; i++) {
		plik.width(20);
		plik.setf(std::ios::left, std::ios::adjustfield);
		plik << gracz_komputerowy[i].akcesor_nazwa();

		plik.width(20);
		plik.setf(std::ios::left, std::ios::adjustfield);
		plik << gracz_komputerowy[i].pokaz_karty();

		plik.width(15);
		plik.setf(std::ios::right, std::ios::adjustfield);
		plik << gracz_komputerowy[i].punkty << std::endl;
	}
	plik.close();
}

void Kasyno::pokaz_talie() {
	Kasyno tmp;
	for (int i = 0; i < 52; i++) {
		//(*tmp.akcesor_talia(i)).wypisz();
		talia[i].wypisz();
	}
	std::cout << std::endl;
}

void Kasyno::Potasuj() {
	Karta* tmp = new Karta[52];
	int n, m;
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		n = rand() % 52;
		m = rand() % 52;

		tmp[n] = talia[n];
		tmp[m] = talia[m];
		talia[n] = tmp[m];
		talia[m] = tmp[n];
	}
	delete[] tmp;
	//pokaz_talie();
}

Karta* Kasyno::dajKarte() {
	Karta* tmp = &talia[akt_karta];
	akt_karta++;
	if (akt_karta == 53)akt_karta = 0;
	return tmp;
}

Karta* Kasyno::akcesor_talia(int i) {
	return &talia[i];
}

