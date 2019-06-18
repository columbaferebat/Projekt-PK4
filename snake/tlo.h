#pragma once
#include "element.h"
class tlo :public element
{
public:
	tlo();
	~tlo();
	void laduj_duszka(Texture &obrazek);
	Sprite wez_duszka();
	void ustaw_pozycje_duszka(float x, float y);
	tlo(Texture& plik);
};