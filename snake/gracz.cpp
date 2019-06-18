#include "gracz.h"

#define stan_stoj 1
#define stan_biegnij 2
#define stan_bij 3

gracz::gracz()
{
}
gracz::~gracz()
{
}
gracz::gracz(Texture & plik)
{
	stan = stan_stoj;
	ilosc_zycia = 10;
	kierunek_lewo = false;
	duszek.setTexture(plik);
	duszek.setPosition(Poczatek_ekranu_X + 250, Poczatek_ekranu_Y + 240);
	this->resetuj_zegar();

}


void gracz::bij(generator_przeciwnikow& generator,int szansa)
{
	this->ustaw_stan(stan_stoj);
	if (this->czy_kierunek_lewo() == true)
	{
		for (int i = 0; i < generator.rozmiar_vectora(); i++)
		{
			przeciwnik* losowy = generator.pobierz_z_vectora(i)->get();
			if (losowy->pobierz_pozycjeX() > Pozycja_bicia_gracza_lewo_X - roznica_pola_bicia && losowy->czy_kierunek_lewo() == false 
				&& losowy->ile_zycia() > 0&&losowy->jaki_rodzaj_przeciwnika()!=rodzajrakieta)
			{
				losowy->odejmij_zycie(szansa);
				losowy->resetuj_zegar();
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < generator.rozmiar_vectora(); i++)
		{
			przeciwnik* losowy = generator.pobierz_z_vectora(i)->get();
			if (losowy->pobierz_pozycjeX() < Pozycja_bicia_gracza_prawo_X+ roznica_pola_bicia && losowy->czy_kierunek_lewo() == true&&losowy->ile_zycia()>0 && losowy->jaki_rodzaj_przeciwnika() != rodzajrakieta)
			{
				losowy->odejmij_zycie(szansa);
				losowy->resetuj_zegar();
				break;
			}
		}
	}
}
void gracz::skacz(generator_przeciwnikow& generator)
{
	if (this->kierunek_lewo==true)
	{
		this->odwroc_duszka_w_lewo();
		this->duszek.setPosition(duszek.getPosition().x + bez_zmiany, duszek.getPosition().y - szybkosc_spadania * modyfikator_grawitacji*(raz_na_pol_sekundy - zegar_animacji));
		for (int i = 0; i < generator.rozmiar_vectora(); i++)
		{
			przeciwnik* losowy = generator.pobierz_z_vectora(i)->get();
			if (losowy->pobierz_pozycjeX() > 150 && losowy->czy_kierunek_lewo() == false && losowy->ile_zycia() > 0 && losowy->jaki_rodzaj_przeciwnika() != rodzajrakieta&&zegar_animacji==7)
			{
				losowy->odejmij_zycie(szansa1na1);
			}
		}
	}
	else
	{
		this->duszek.setPosition(duszek.getPosition().x + bez_zmiany, duszek.getPosition().y - szybkosc_spadania * modyfikator_grawitacji*(raz_na_pol_sekundy - zegar_animacji));
		for (int i = 0; i < generator.rozmiar_vectora(); i++)
		{
			przeciwnik* losowy = generator.pobierz_z_vectora(i)->get();
			if (losowy->pobierz_pozycjeX() < 330 && losowy->czy_kierunek_lewo() == true && losowy->ile_zycia() > 0 && losowy->jaki_rodzaj_przeciwnika() != rodzajrakieta && zegar_animacji == 7)
			{
				losowy->odejmij_zycie(szansa1na1);
			}
		}
	}

	if (zegar_animacji == raz_na_sekunde)
	{
		this->resetuj_zegar();
		this->ustaw_stan(stan_stoj);
	}

}
void gracz::odejmij_zycie()
{
	this->ilosc_zycia--;
	if (ilosc_zycia < 1)
	{
		ilosc_zycia = 0;
	}
}
void gracz::umarl()
{
	duszek.setRotation(90);
	duszek.setPosition(Poczatek_ekranu_X + 520, Poczatek_ekranu_Y + 275);
}