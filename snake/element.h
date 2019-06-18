#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdio>
#include <vector>
#include <Windows.h>
#include <memory>
#include <map>
#include <string>
#define NOMINMAX

enum nazwy_textur
{
	tlo_gry,koniec_gry,

	gracz_stoi1,gracz_stoi2, gracz_stoi3,
	gracz_bije, gracz_skacze,gracz_kopie,

	pomagier_stoi,pomagier_bije,pomagier_lezy,
	pomagier_biegnie1, pomagier_biegnie2, pomagier_biegnie3,

	boss_stoi, boss_bije, boss_lezy,
	boss_biegnie1, boss_biegnie2, boss_biegnie3,

	rakieta_leci1, rakieta_leci2, rakieta_leci3,rakieta_wybucha
};

#define czestoscpojawianiasieprzeciwnikow 13

#define maxliczbarakiet 2
#define maxliczapomagierow 9
#define maxliczbabossow 4

#define pozycjaX_gameover 240
#define pozycjaY_gameover 20

#define przycisk_W 0
#define przycisk_A 1
#define przycisk_S 2
#define przycisk_D 3

#define szybkosc_biegania	-2		//ma byc -2!!
#define szybkosc_odepchniecia 3
#define szybkosc_spadania 2
#define bez_zmiany			0
#define obracaj_o_1_stopien 1

#define szansa1na4 4 
#define szansa1na2 2
#define szansa1na1 1

#define rodzajpomagier 0
#define rodzajboss 1
#define rodzajrakieta 2

#define Poczatek_ekranu_X	0
#define Poczatek_ekranu_Y	0
#define Pozycja_bicia_gracza_lewo_X 180
#define Pozycja_bicia_gracza_prawo_X 300
#define roznica_pola_bicia 30
#define zasieg_rakiety 100
#define Pozycja_areny 240

#define modyfikator_grawitacji 0.2
#define modyfikator_tarcia 0.04
#define modyfikator_spadania 0.1

#define warunek_rozbieznosci rand() % 2 == 0

#define stan_stoj 1
#define stan_biegnij 2
#define stan_bij 3
#define stan_lez 4
#define stan_skacz 5
#define stan_kop 6
#define stan_wybuch 7

#define koniec_ekranu_lewo -250
#define koniec_ekranu_prawo 900

#define start_animacji 0
#define raz_na_sekunde 60
#define raz_na_pol_sekundy 30
#define raz_na_poltora_sekundy 90
#define raz_na_dwie_sekundy 120

#define jednatrzeciaanimacji 20
#define dwietrzecieanimacji 40

#define pierwsza_textura 0
#define druga_textura 1
#define trzecia_textura 2

using namespace sf;

class element
{
public:
	element();
	~element();

protected:
	Sprite duszek;
	virtual void laduj_duszka(Texture& obrazek) = 0;
	virtual Sprite wez_duszka() = 0;
	virtual void ustaw_pozycje_duszka(float x, float y) = 0;

};