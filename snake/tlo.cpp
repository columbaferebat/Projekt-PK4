#include "tlo.h"



tlo::tlo()
{
}


tlo::~tlo()
{
}
void tlo::laduj_duszka(Texture &obrazek)
{
	duszek.setTexture(obrazek);
}

Sprite tlo::wez_duszka()
{
	return this->duszek;
}

void tlo::ustaw_pozycje_duszka(float x, float y)
{
	duszek.setPosition(x, y);
}

tlo::tlo(Texture& plik)
{
	duszek.setTexture(plik);
	duszek.setPosition(Poczatek_ekranu_X, Poczatek_ekranu_Y);
}