#include "postac.h"


Sprite postac::wez_duszka()
{
	return this->duszek;
}
void postac::laduj_duszka(Texture &obrazek)
{
	duszek.setTexture(obrazek,true);
}
void postac::ustaw_pozycje_duszka(float x, float y)
{
	duszek.setPosition(x, y);
}
void  postac::zmien_pozycje(int x, int y)
{
	this->ustaw_pozycje_duszka(this->duszek.getPosition().x + x, this->duszek.getPosition().y + y);
}
void postac::odwroc_duszka_w_lewo()
{
	if (duszek.getTextureRect().width > 0)
	{
		duszek.setTextureRect(sf::IntRect(duszek.getTextureRect().width, 0, -duszek.getTextureRect().width, duszek.getTextureRect().height));

	}
	else if (duszek.getTextureRect().width < 0)
	{
		duszek.setTextureRect(sf::IntRect(-duszek.getTextureRect().width, 0, duszek.getTextureRect().width, duszek.getTextureRect().height));
	}
}
void postac::odwroc_duszka_w_prawo()
{
	if (duszek.getTextureRect().width > 0)
	{
		duszek.setTextureRect(sf::IntRect(0, 0, duszek.getTextureRect().width, duszek.getTextureRect().height));
	}
	else if (duszek.getTextureRect().width < 0)
	{
		duszek.setTextureRect(sf::IntRect(0, 0, -duszek.getTextureRect().width, duszek.getTextureRect().height));
	}
}
int postac::pobierz_pozycjeX()
{
	return this->duszek.getPosition().x;
}
void postac::ustaw_kierunek(bool lewo)
{
	kierunek_lewo = lewo;
}
int postac::ile_na_zegarze()
{
	return this->zegar_animacji;
}
void postac::resetuj_zegar()
{
	this->zegar_animacji = 0;
}
void postac::ustaw_stan(int stan)
{
	this->stan = stan;
}
void postac::inkrementuj_zegar()
{
	zegar_animacji++;
}
int postac::jaki_stan()
{
	return this->stan;
}
int postac::ile_zycia()
{
	return this->ilosc_zycia;
}
bool postac::czy_kierunek_lewo()
{
	return this->kierunek_lewo;
}