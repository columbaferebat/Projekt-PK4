#include "animacja_gracza.h"

animacja_gracza::animacja_gracza()
{
}
animacja_gracza::~animacja_gracza()
{
}
animacja_gracza::animacja_gracza(gracz* gracz1, std::map<nazwy_textur, Texture>& kontener)
{
	this->gracz1 = gracz1;
	this->gracz_stoi[0] = kontener.find(gracz_stoi1)->second;
	this->gracz_stoi[1] = kontener.find(gracz_stoi2)->second;
	this->gracz_stoi[2] = kontener.find(gracz_stoi3)->second;
	this->gracz_skacze = kontener.find(nazwy_textur::gracz_skacze)->second;
	this->gracz_kopie = kontener.find(nazwy_textur::gracz_kopie)->second;
	this->gracz_bije = kontener.find(nazwy_textur::gracz_bije)->second;
}
void animacja_gracza::animuj_gracza(generator_przeciwnikow &generator)
{

	if (gracz1->jaki_stan() == stan_bij)
	{
		gracz1->laduj_duszka(this->gracz_bije);
		gracz1->bij(generator,szansa1na4);
	}
	else if (gracz1->jaki_stan() == stan_skacz)
	{
		gracz1->laduj_duszka(this->gracz_skacze);
		gracz1->skacz(generator);
	}
	else if (gracz1->jaki_stan() == stan_kop)
	{
		gracz1->laduj_duszka(this->gracz_kopie);
		gracz1->bij(generator, szansa1na2);
	}

	gracz1->inkrementuj_zegar();
	if (gracz1->jaki_stan() != stan_skacz)
	{
		if (gracz1->ile_na_zegarze() == start_animacji + 20 || gracz1->ile_na_zegarze() == start_animacji + 60)
		{
			gracz1->ustaw_stan(stan_stoj);
			gracz1->laduj_duszka(this->gracz_stoi[pierwsza_textura]);
		}
		else if (gracz1->ile_na_zegarze() == start_animacji + 40)
		{
			gracz1->ustaw_stan(stan_stoj);
			gracz1->laduj_duszka(this->gracz_stoi[druga_textura]);
		}
		else if (gracz1->ile_na_zegarze() == start_animacji + 80)
		{
			gracz1->ustaw_stan(stan_stoj);
			gracz1->laduj_duszka(this->gracz_stoi[trzecia_textura]);
			gracz1->resetuj_zegar();
		}
		if (gracz1->czy_kierunek_lewo() == true)
		{
			gracz1->odwroc_duszka_w_lewo();
		}
		else
		{
			gracz1->odwroc_duszka_w_prawo();
		}
	}
}


