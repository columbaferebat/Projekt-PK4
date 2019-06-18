#include "definicje.h"

using namespace sf;
using namespace std;

int main()
{
	srand(time(NULL));
	int ilosc_zabitych = 0;
	RenderWindow okno(VideoMode(833, 511), "Action");
	okno.setFramerateLimit(raz_na_sekunde);
	Event wydarzenie;

	Font czcionka;
	czcionka.loadFromFile("Font/Lato-Regular.ttf");
	Text wynik_koncowy;
	string napis_koncowy="Udalo ci sie zabic ";
	bool ilosc_przeciwnikow_wypisana = false;
	test_jednostkowy(999999.2121132132132);

	auto kontener = map<nazwy_textur,Texture>();
	sf::Texture zycie[11];
	laduj_Textury(kontener,zycie);

	Sprite napis_koniec(kontener.find(koniec_gry)->second);
	napis_koniec.setPosition(pozycjaX_gameover, pozycjaY_gameover);

	przeciwnik pomagier(rodzajpomagier);		
	przeciwnik boss(rodzajboss);		
	przeciwnik rakieta1(rodzajrakieta);		
	generator_przeciwnikow generator(&pomagier, &boss, &rakieta1);

	animacja_przeciwnika rakieta_animacja(kontener, rodzajrakieta);
	animacja_przeciwnika pomagier_animacja(kontener, rodzajpomagier);
	animacja_przeciwnika boss_animacja(kontener, rodzajboss);

	tlo tlo1(kontener.find(tlo_gry)->second);

	gracz* gracz1=new gracz(kontener.find(gracz_stoi1)->second);
	animacja_gracza gracz_animacja(gracz1, kontener);

	pasek_zycia zycie_pasek(zycie[10], Poczatek_ekranu_X + 30, Poczatek_ekranu_Y + 40);

	bool przyciski[4] = {true,true,true,true};
	okno.setMouseCursorVisible(false);

	while (okno.isOpen())
	{
		okno.pollEvent(wydarzenie);

		sprawdz_sterowanie(wydarzenie, *gracz1, przyciski);
		if (wydarzenie.type == Event::Closed)
		{
			okno.close();
		}
		if (wydarzenie.type == Event::KeyPressed)
		{
			if (wydarzenie.key.code == Keyboard::Escape) okno.close();
		}
		okno.draw(tlo1.wez_duszka());
		okno.draw(gracz1->wez_duszka());

		generator.generuj_przeciwnika();

		for (int i = 0; i < generator.rozmiar_vectora(); i++)
		{
			int rodzaj_przeciwnika = generator.pobierz_z_vectora(i)->get()->jaki_rodzaj_przeciwnika();
			if (rodzaj_przeciwnika == rodzajpomagier)
			{
				pomagier_animacja.animuj(generator, i,*gracz1, ilosc_zabitych);
			}
			else if (rodzaj_przeciwnika == rodzajboss)
			{
				boss_animacja.animuj(generator, i, *gracz1, ilosc_zabitych);
			}
			else if (rodzaj_przeciwnika == rodzajrakieta)
			{
				rakieta_animacja.animuj(generator, i, *gracz1, ilosc_zabitych);
			}
			if (generator.rozmiar_vectora()>i)
			{
				okno.draw(generator.pobierz_z_vectora(i)->get()->wez_duszka());
			}
		}
		zycie_pasek.laduj_duszka(zycie[gracz1->ile_zycia()]);


		okno.draw(zycie_pasek.wez_duszka());
		
		gracz_animacja.animuj_gracza(generator);
		if (gracz1->ile_zycia() < 1)
		{
			gracz1->laduj_duszka(kontener.find(gracz_stoi1)->second);
			koniec(przyciski, *gracz1, ilosc_przeciwnikow_wypisana, napis_koncowy, ilosc_zabitych);
			okno.draw(napis_koniec);
			ustaw_tekst(wynik_koncowy, czcionka, napis_koncowy);
			okno.draw(wynik_koncowy);
		}
		okno.display();
	}
	delete gracz1;
	generator.~generator_przeciwnikow();
}

//max 200 linii na klase
//max 50 linii na metode

/*
Zrobione:
zrobiæ dodawanie przeciwników przez iteratory
MOZE za dlugi main
rakiety
za d³uga klasa przeciwnik - wpisaæ czeœæ metod do klasy postac
wypisanie przy gameover ile przeciwnikow sie zabilo
kontener na textury map<> - MOZNA OD RAZU ZROBIC TRY/CATCH	
skakanie i jaki to ma miec sens?
*/



