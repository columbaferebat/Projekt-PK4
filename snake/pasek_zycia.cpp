#include "pasek_zycia.h"



pasek_zycia::pasek_zycia()
{
}


pasek_zycia::~pasek_zycia()
{
}
pasek_zycia::pasek_zycia(Texture& plik, float pozycjaX, float pozycjaY)
{
	duszek.setTexture(plik);
	duszek.setPosition(pozycjaX, pozycjaY);
}
void pasek_zycia::laduj_duszka(Texture &obrazek)
{
	duszek.setTexture(obrazek);
}
Sprite pasek_zycia::wez_duszka()
{
	return this->duszek;
}
void pasek_zycia::ustaw_pozycje_duszka(float x, float y)
{
	duszek.setPosition(x, y);
}
