#pragma once
#include "element.h"

class postac : public element
{
protected:
	int stan;
	int ilosc_zycia;
	bool kierunek_lewo;
	int zegar_animacji;
public:
	void zmien_pozycje(int x, int y);
	int	pobierz_pozycjeX();
	void ustaw_pozycje_duszka(float x, float y);
	void laduj_duszka(Texture& obrazek);
	Sprite wez_duszka();
	int ile_zycia();
	bool czy_kierunek_lewo();
	void ustaw_kierunek(bool lewo);
	void odwroc_duszka_w_lewo();
	void odwroc_duszka_w_prawo();
	void inkrementuj_zegar();
	void resetuj_zegar();
	int ile_na_zegarze();
	void ustaw_stan(int stan);
	int jaki_stan();

};
