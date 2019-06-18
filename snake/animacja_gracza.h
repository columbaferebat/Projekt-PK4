#pragma once
#include "gracz.h"
#include "generator_przeciwnikow.h"
class animacja_gracza
{
	gracz* gracz1;
	sf::Texture gracz_stoi[3];
	sf::Texture gracz_bije;
	sf::Texture gracz_skacze;
	sf::Texture gracz_kopie;
public:
	animacja_gracza();
	animacja_gracza(gracz* gracz1, std::map<nazwy_textur, Texture>& kontener);
	~animacja_gracza();
	void animuj_gracza(generator_przeciwnikow &generator);
};

