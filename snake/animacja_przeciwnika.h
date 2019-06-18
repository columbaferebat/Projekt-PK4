#pragma once
#include "generator_przeciwnikow.h"
#include "definicje.h"
class animacja_przeciwnika
{
	Texture bij;
	Texture biegnij[3];
	Texture stoj;
	Texture lez;
public:
	animacja_przeciwnika(std::map<nazwy_textur, Texture>& kontener,int rodzaj_przeciwinika);
	animacja_przeciwnika();
	~animacja_przeciwnika();
	Texture *pobierz_Texture_bij();
	Texture *pobierz_Texture_stoj();
	Texture *pobierz_Texture_lez();
	Texture *pobierz_Texture_biegnij();
	void animuj(generator_przeciwnikow &generator,int i,gracz& gracz1, int& ilosc_zabitych);
};

