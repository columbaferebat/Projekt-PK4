#pragma once
#include "element.h"
class pasek_zycia :public element
{
public:
	pasek_zycia(Texture& plik, float pozycjaX, float pozycjaY);
	pasek_zycia();
	~pasek_zycia();
	void laduj_duszka(Texture& obrazek);
	Sprite wez_duszka();
	void ustaw_pozycje_duszka(float x, float y);
};
