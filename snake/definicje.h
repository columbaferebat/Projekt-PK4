#pragma once
#include "gracz.h"
#include "generator_przeciwnikow.h"
#include "generator_przeciwnikow.h"
#include "pasek_zycia.h"
#include "tlo.h"
#include "animacja_przeciwnika.h"
#include "animacja_gracza.h"

using namespace sf;
using namespace std;

void laduj_Textury(map<nazwy_textur,Texture>& kontener,sf::Texture* zycie);

void sprawdz_sterowanie(Event wydarzenie, gracz& gracz1, bool* przyciski);

void koniec(bool * przyciski, gracz& gracz1, bool& ilosc_przeciwnikow_wypisana, string& wynik_koncowy, int ilosc_zabitych);


void sprawdz_zaladowanie_textur(map<nazwy_textur, Texture>& kontener);

void ustaw_tekst(Text &text1, Font& czcionka, string napis_koncowy);

string int_na_string(int liczba);

void test_jednostkowy(int liczba);
