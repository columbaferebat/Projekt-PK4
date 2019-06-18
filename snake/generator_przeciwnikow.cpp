#include "generator_przeciwnikow.h"



generator_przeciwnikow::generator_przeciwnikow()
{
}

void generator_przeciwnikow::losuj_kierunek()
{
	int ostatni = this->vector_przeciwnikow.size() - 1;
	if (rand() % 2 == 0)
	{
		this->vector_przeciwnikow[ostatni]->ustaw_kierunek(true);
	}
	else
	{
		this->vector_przeciwnikow[ostatni]->ustaw_kierunek(false);
	}
}
void generator_przeciwnikow::ustaw_przeciwnika()
{
	int ostatni = this->vector_przeciwnikow.size() - 1;
	if (this->vector_przeciwnikow[ostatni]->czy_kierunek_lewo() == true)
	{
		if (this->vector_przeciwnikow[ostatni]->jaki_rodzaj_przeciwnika() == rodzajrakieta)
		{
			this->vector_przeciwnikow[ostatni]->ustaw_pozycje_duszka(koniec_ekranu_prawo, Poczatek_ekranu_Y + 50);
		}
		else
		{
			this->vector_przeciwnikow[ostatni]->ustaw_pozycje_duszka(koniec_ekranu_prawo, Poczatek_ekranu_Y + 240);
		}
	}
	else
	{
		if (this->vector_przeciwnikow[ostatni]->jaki_rodzaj_przeciwnika() == rodzajrakieta)
		{
			this->vector_przeciwnikow[ostatni]->ustaw_pozycje_duszka(koniec_ekranu_lewo, Poczatek_ekranu_Y + 50);
		}
		else
		{
			this->vector_przeciwnikow[ostatni]->ustaw_pozycje_duszka(koniec_ekranu_lewo, Poczatek_ekranu_Y + 240);
		}
	}
}
void generator_przeciwnikow::usun_z_vectora(int pozycja)
{
	ilosc_przeciwnikow[this->pobierz_z_vectora(pozycja)->get()->jaki_rodzaj_przeciwnika()]--;
	vector_przeciwnikow.erase(vector_przeciwnikow.begin() + pozycja);
}
void generator_przeciwnikow::generuj_przeciwnika()		
{
	int losowy_przeciwnik = rand() % 6; 
	if (rand() % czestoscpojawianiasieprzeciwnikow == 0)
	{
		if (losowy_przeciwnik == 0 && ilosc_przeciwnikow[rodzajrakieta] < maxliczbarakiet)
		{
			ilosc_przeciwnikow[rodzajrakieta]++;
			dodaj_przeciwnika(rakieta);
			losuj_kierunek();
			ustaw_przeciwnika();

		}
		else if (losowy_przeciwnik < 5 && ilosc_przeciwnikow[rodzajpomagier] < maxliczapomagierow)
		{
			ilosc_przeciwnikow[rodzajpomagier]++;
			dodaj_przeciwnika(pomagier);
			losuj_kierunek();
			ustaw_przeciwnika();
		}
		else if (losowy_przeciwnik == 5 && ilosc_przeciwnikow[rodzajboss] < maxliczbabossow)
		{
			ilosc_przeciwnikow[rodzajboss]++;
			dodaj_przeciwnika(boss);
			losuj_kierunek();
			ustaw_przeciwnika();
		}
	}
}
void generator_przeciwnikow::dodaj_przeciwnika(przeciwnik* x1)		//tu jest problem unique_ptr!!!! - naprawione
{
	std::back_insert_iterator<std::vector<std::unique_ptr<przeciwnik>> > na_koniec(vector_przeciwnikow);
	przeciwnik* nowy = new przeciwnik();							//TUTAJ MOGA BYC WYCIEKI
	nowy->konstruktor(*x1);
	std::unique_ptr<przeciwnik> wskaznik(nowy);
	*na_koniec = std::move(wskaznik);
}
generator_przeciwnikow::generator_przeciwnikow(przeciwnik* przeciwnik1, przeciwnik *przeciwnik2, przeciwnik* przeciwnik3)
{
	pomagier = przeciwnik1;
	boss = przeciwnik2;
	rakieta = przeciwnik3;
	ilosc_przeciwnikow[rodzajboss] = 0;
	ilosc_przeciwnikow[rodzajpomagier] = 0;
	ilosc_przeciwnikow[rodzajrakieta] = 0;
}
generator_przeciwnikow::~generator_przeciwnikow()
{
	vector_przeciwnikow.clear();
}
std::unique_ptr<przeciwnik>* generator_przeciwnikow::pobierz_z_vectora(int pozycja)
{
	return &vector_przeciwnikow[pozycja];
}
int generator_przeciwnikow::rozmiar_vectora()
{
	return vector_przeciwnikow.size();
}
