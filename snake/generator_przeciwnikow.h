#pragma once
#include "przeciwnik.h"
#include <iterator>



class generator_przeciwnikow
{
	std::vector<std::unique_ptr<przeciwnik>> vector_przeciwnikow;
	int ilosc_przeciwnikow[3];
	void dodaj_przeciwnika(przeciwnik* x1);
	przeciwnik* pomagier,* boss, *rakieta;

public:
	generator_przeciwnikow();
	~generator_przeciwnikow();
	void losuj_kierunek();
	void ustaw_przeciwnika();

	void generuj_przeciwnika();
	void usun_z_vectora(int pozycja);
	generator_przeciwnikow(przeciwnik* przeciwnik1, przeciwnik *przeciwnik2, przeciwnik *przeciwnik3);
	std::unique_ptr<przeciwnik>* pobierz_z_vectora(int pozycja);
	int rozmiar_vectora();
};
