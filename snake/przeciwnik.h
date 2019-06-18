#pragma once
#include "postac.h"

class przeciwnik :public postac
{
protected:
	int rodzaj_przeciwnika;
public:
	przeciwnik();
	~przeciwnik();
	void biegnij(Texture* duszek);
	void stoj(Texture& duszek);
	bool lez(Texture& duszek);
	void bij(Texture& duszek,Texture& stoi);
	void lec(Texture& duszek, int stan_gracz, int zegar_gracz);
	bool wybuch(Texture& obrazek);
	przeciwnik(int rodzaj_przeciwnika);
	przeciwnik* konstruktor(const przeciwnik& kopia);
	int jaki_rodzaj_przeciwnika();
	void odejmij_zycie(int szansa);
};