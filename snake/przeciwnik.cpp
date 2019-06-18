#include "przeciwnik.h"

przeciwnik::przeciwnik()
{
}
przeciwnik::~przeciwnik()
{
}
int przeciwnik::jaki_rodzaj_przeciwnika()
{
	return this->rodzaj_przeciwnika;
}
bool przeciwnik::lez(Texture& duszek)	
{												//funkcja zwraca wartosc czy przeciwnika mozna skasowac
	zegar_animacji++;
	this->laduj_duszka(duszek);
	if (this->ile_zycia()<1)
	{
		if (zegar_animacji < raz_na_dwie_sekundy)
		{
			if (this->kierunek_lewo == true)
			{
				this->odwroc_duszka_w_lewo();
				this->zmien_pozycje(szybkosc_odepchniecia, 2*(szybkosc_spadania - modyfikator_spadania *(raz_na_sekunde - zegar_animacji)));
			}
			else
			{
				this->odwroc_duszka_w_prawo();
				this->zmien_pozycje(-szybkosc_odepchniecia, 2*(szybkosc_spadania - modyfikator_spadania * (raz_na_sekunde - zegar_animacji)));
			}
		}
		else
		{
			return true;
		}
	}
	else
	{
		if (zegar_animacji == raz_na_sekunde)
		{
			this->resetuj_zegar();
			this->ustaw_stan(stan_biegnij);
		}
		if (this->kierunek_lewo == true)
		{
			this->odwroc_duszka_w_lewo();
			this->zmien_pozycje(szybkosc_odepchniecia* (raz_na_sekunde - zegar_animacji)*modyfikator_tarcia, bez_zmiany);
		}
		else
		{
			this->odwroc_duszka_w_prawo();
			this->zmien_pozycje(-szybkosc_odepchniecia * (raz_na_sekunde - zegar_animacji)*modyfikator_tarcia, bez_zmiany);
		}
	}
	return false;
}
void przeciwnik::bij(Texture& duszek,Texture& stoi)
{
	zegar_animacji++;
	if (zegar_animacji > raz_na_sekunde)
	{
		this->laduj_duszka(duszek);
		if (zegar_animacji ==raz_na_poltora_sekundy)
		{
			this->resetuj_zegar();
		}
	}
	else
	{
		this->laduj_duszka(stoi);
	}
	if (this->kierunek_lewo == true)
	{
		this->odwroc_duszka_w_lewo();
	}
	else
	{
		this->odwroc_duszka_w_prawo();
	}
}
void przeciwnik::stoj(Texture& duszek)
{
	this->laduj_duszka(duszek);
}
bool przeciwnik::wybuch(Texture& obrazek)
{
	this->laduj_duszka(obrazek);
	this->inkrementuj_zegar();
	if (this->zegar_animacji == raz_na_pol_sekundy)
	{
		return true;
	}
	return false;
}
void przeciwnik::biegnij(Texture* animacja)
{
	this->inkrementuj_zegar();
	if (this->ile_na_zegarze() == start_animacji + 20 || this->ile_na_zegarze() == start_animacji + 60)
	{
		this->laduj_duszka(animacja[pierwsza_textura]);
	}
	else if (this->ile_na_zegarze() == start_animacji + 40)
	{
		this->laduj_duszka(animacja[druga_textura]);
	}
	else if (this->ile_na_zegarze() == start_animacji + 80)
	{
		this->laduj_duszka(animacja[trzecia_textura]);
		this->resetuj_zegar();
	}
	if (this->kierunek_lewo == true)
	{
		this->odwroc_duszka_w_lewo();
		this->zmien_pozycje(szybkosc_biegania, bez_zmiany);
		if (this->pobierz_pozycjeX() < Pozycja_bicia_gracza_prawo_X && warunek_rozbieznosci)
		{
			this->ustaw_stan(stan_bij);
		}
	}
	else
	{
		if (this->pobierz_pozycjeX() > Pozycja_bicia_gracza_lewo_X && warunek_rozbieznosci)
		{
			this->ustaw_stan(stan_bij);
		}
		this->odwroc_duszka_w_prawo();
		this->zmien_pozycje(-szybkosc_biegania, bez_zmiany);
	}
}
void przeciwnik::lec(Texture& duszek,int stan_gracz,int zegar_gracz)
{
	this->laduj_duszka(duszek);
	if (this->kierunek_lewo == true)
	{
		this->odwroc_duszka_w_lewo();
		this->zmien_pozycje(szybkosc_biegania*2, bez_zmiany);
		if (this->pobierz_pozycjeX() < Pozycja_bicia_gracza_prawo_X + zasieg_rakiety &&stan_gracz ==stan_skacz  
			&&this->pobierz_pozycjeX() > Pozycja_bicia_gracza_lewo_X+ roznica_pola_bicia)
		{
			if (zegar_gracz > jednatrzeciaanimacji && zegar_gracz < dwietrzecieanimacji)
			{
				this->resetuj_zegar();
				this->ustaw_stan(stan_bij);
			}
		}
	}
	else
	{
		if (this->pobierz_pozycjeX() > Pozycja_bicia_gracza_lewo_X - zasieg_rakiety &&stan_gracz == stan_skacz
			&&this->pobierz_pozycjeX() < Pozycja_bicia_gracza_prawo_X- roznica_pola_bicia)
		{
			if (zegar_gracz > jednatrzeciaanimacji && zegar_gracz < dwietrzecieanimacji)
			{
				this->resetuj_zegar();
				this->ustaw_stan(stan_bij);
			}
		}
		this->odwroc_duszka_w_prawo();
		this->zmien_pozycje(-szybkosc_biegania*2, bez_zmiany);
	}
	if (this->pobierz_pozycjeX() < koniec_ekranu_lewo|| this->pobierz_pozycjeX() > koniec_ekranu_prawo)
	{
		kierunek_lewo = !kierunek_lewo;
	}
}
przeciwnik::przeciwnik(int rodzaj)
{
	if (rodzaj == rodzajboss)
	{
		ilosc_zycia = 7;
	}
	else if (rodzaj == rodzajpomagier)
	{
		ilosc_zycia = 4;
	}
	else
	{
		ilosc_zycia = 1;
	}
	kierunek_lewo = false;
	zegar_animacji = 0;
	rodzaj_przeciwnika = rodzaj;
	stan = stan_biegnij;
}
przeciwnik* przeciwnik::konstruktor(const przeciwnik& kopia)
{
	ilosc_zycia = kopia.ilosc_zycia;
	kierunek_lewo = false;
	zegar_animacji = 0;
	rodzaj_przeciwnika = kopia.rodzaj_przeciwnika;
	stan = stan_biegnij;
	return this;
}
void przeciwnik::odejmij_zycie(int szansa_na_przewrocenie)		
{
	this->ilosc_zycia = ilosc_zycia - 1;
	ustaw_stan(stan_biegnij);
	this->resetuj_zegar();
	if (rand() % szansa_na_przewrocenie==0 && ilosc_zycia > 0)
	{
		this->resetuj_zegar();
		this->ustaw_stan(stan_lez);
	}
}
