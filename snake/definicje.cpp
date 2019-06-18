#include "definicje.h"


#define stan_stoj 1
#define stan_biegnij 2
#define stan_bij 3
#define stan_lez 4
#define stan_skacz 5

#define wychodzi_z_lewej_strony_X 50
#define wychodzi_z_prawej_strony_X 700
#define poziom_areny 300


void laduj_Textury(map<nazwy_textur, Texture>& kontener,Texture* zycie)
{

		zycie[10].loadFromFile("grafika/zycie1.png");
		zycie[9].loadFromFile("grafika/zycie2.png");
		zycie[8].loadFromFile("grafika/zycie3.png");
		zycie[7].loadFromFile("grafika/zycie4.png");
		zycie[6].loadFromFile("grafika/zycie5.png");
		zycie[5].loadFromFile("grafika/zycie6.png");
		zycie[4].loadFromFile("grafika/zycie7.png");
		zycie[3].loadFromFile("grafika/zycie8.png");
		zycie[2].loadFromFile("grafika/zycie9.png");
		zycie[1].loadFromFile("grafika/zycie10.png");
		zycie[0].loadFromFile("grafika/zycie11.png");

		Texture tmp[24];
		tmp[0].loadFromFile("grafika/zrzut1.png");
		kontener.insert(pair<nazwy_textur, Texture>(tlo_gry, tmp[0]));
		tmp[1].loadFromFile("grafika/gameover.png");
		kontener.insert(pair<nazwy_textur, Texture>(koniec_gry, tmp[1]));

		tmp[2].loadFromFile("grafika/pomagierstoi.png");				//pomagier
		kontener.insert(pair<nazwy_textur, Texture>(pomagier_stoi, tmp[2]));
		tmp[3].loadFromFile("grafika/pomagierbiegnie1.png");
		kontener.insert(pair<nazwy_textur, Texture>(pomagier_biegnie3, tmp[3]));
		tmp[23].loadFromFile("grafika/pomagierbiegnie3.png");
		kontener.insert(pair<nazwy_textur, Texture>(pomagier_biegnie2, tmp[23]));
		tmp[4].loadFromFile("grafika/pomagierbiegnie2.png");
		kontener.insert(pair<nazwy_textur, Texture>(pomagier_biegnie1, tmp[4]));
		tmp[5].loadFromFile("grafika/pomagierbije.png");
		kontener.insert(pair<nazwy_textur, Texture>(pomagier_bije, tmp[5]));
		tmp[6].loadFromFile("grafika/pomagierlezy.png");
		kontener.insert(pair<nazwy_textur, Texture>(pomagier_lezy, tmp[6]));

		tmp[7].loadFromFile("grafika/rakietaleci1.png");						//rakieta
		kontener.insert(pair<nazwy_textur, Texture>(rakieta_leci1, tmp[7]));
		tmp[8].loadFromFile("grafika/rakietaleci1.png");
		kontener.insert(pair<nazwy_textur, Texture>(rakieta_leci2, tmp[8]));
		tmp[9].loadFromFile("grafika/rakietaleci1.png");
		kontener.insert(pair<nazwy_textur, Texture>(rakieta_leci3, tmp[9]));
		tmp[10].loadFromFile("grafika/rakietawybucha.png");
		kontener.insert(pair<nazwy_textur, Texture>(rakieta_wybucha, tmp[10]));

		tmp[11].loadFromFile("grafika/bossstoi.png");						//boss
		kontener.insert(pair<nazwy_textur, Texture>(boss_stoi, tmp[11]));
		tmp[12].loadFromFile("grafika/bossbiegnie1.png");
		kontener.insert(pair<nazwy_textur, Texture>(boss_biegnie1, tmp[12]));
		tmp[13].loadFromFile("grafika/bossbiegnie2.png");
		kontener.insert(pair<nazwy_textur, Texture>(boss_biegnie2, tmp[13]));
		tmp[14].loadFromFile("grafika/bossbiegnie3.png");
		kontener.insert(pair<nazwy_textur, Texture>(boss_biegnie3, tmp[14]));
		tmp[15].loadFromFile("grafika/bossbije.png");
		kontener.insert(pair<nazwy_textur, Texture>(boss_bije, tmp[15]));
		tmp[16].loadFromFile("grafika/bosslezy.png");
		kontener.insert(pair<nazwy_textur, Texture>(boss_lezy, tmp[16]));

		tmp[17].loadFromFile("grafika/gracz2.png");							//gracz
		kontener.insert(pair<nazwy_textur, Texture>(gracz_stoi1, tmp[17]));
		tmp[18].loadFromFile("grafika/gracz1.png");
		kontener.insert(pair<nazwy_textur, Texture>(gracz_stoi2, tmp[18]));
		tmp[19].loadFromFile("grafika/gracz3.png");
		kontener.insert(pair<nazwy_textur, Texture>(gracz_stoi3, tmp[19]));
		tmp[20].loadFromFile("grafika/graczuderza.png");
		kontener.insert(pair<nazwy_textur, Texture>(gracz_bije, tmp[20]));
		tmp[21].loadFromFile("grafika/graczskacze.png");
		kontener.insert(pair<nazwy_textur, Texture>(gracz_skacze, tmp[21]));
		tmp[22].loadFromFile("grafika/graczkopie.png");
		kontener.insert(pair<nazwy_textur, Texture>(gracz_kopie, tmp[22]));

	sprawdz_zaladowanie_textur(kontener);
}

void sprawdz_zaladowanie_textur(map<nazwy_textur, Texture>& kontener)
{
	string blad = "ERROR";
	for (auto it = kontener.begin(); it != kontener.end(); it++)
	{
		if ((*it).second.getSize().x == 0)
		{
			throw blad;
		}
	}
}

void sprawdz_sterowanie(Event wydarzenie,gracz& gracz1, bool* przyciski)
{
	switch (wydarzenie.type)
	{
	case Event::KeyPressed:

		if (wydarzenie.key.code == Keyboard::W&&przyciski[przycisk_W])
		{
			if (gracz1.jaki_stan() != stan_skacz)
			{
				gracz1.resetuj_zegar();
			}
			gracz1.ustaw_stan(stan_skacz);
			przyciski[przycisk_W] = false;
		}
		else if (wydarzenie.key.code == Keyboard::A&&przyciski[przycisk_A]&&gracz1.jaki_stan()!=stan_skacz)
		{
			gracz1.ustaw_stan(stan_bij);
			gracz1.ustaw_kierunek(true);
			gracz1.resetuj_zegar();
			przyciski[przycisk_A] = false;
		}
		else if (wydarzenie.key.code == Keyboard::S&&przyciski[przycisk_S]&&gracz1.jaki_stan() != stan_skacz)
		{
			gracz1.ustaw_stan(stan_kop);
			gracz1.resetuj_zegar();
			przyciski[przycisk_S] = false;
		}
		else if (wydarzenie.key.code == Keyboard::D&&przyciski[przycisk_D]&&gracz1.jaki_stan() != stan_skacz)
		{
			gracz1.ustaw_stan(stan_bij);
			gracz1.ustaw_kierunek(false);
			gracz1.resetuj_zegar();
			przyciski[przycisk_D] = false;
		}
		break;
	case Event::KeyReleased:
		if (wydarzenie.key.code == Keyboard::W)
		{
			przyciski[przycisk_W] = true;
		}
		else if (wydarzenie.key.code == Keyboard::A)
		{
			przyciski[przycisk_A] = true;
		}
		else if (wydarzenie.key.code == Keyboard::S)
		{
			przyciski[przycisk_S] = true;
		}
		else if (wydarzenie.key.code == Keyboard::D)
		{
			przyciski[przycisk_D] = true;
		}
		break;

	case Event::EventType::TextEntered:

		//cout << wydarzenie.text.unicode << endl;

		break;
	}
}

void koniec(bool * przyciski, gracz& gracz1,bool& ilosc_przeciwnikow_wypisana,string &wynik_koncowy,int ilosc_zabitych)
{
	if (ilosc_przeciwnikow_wypisana == false)
	{
		wynik_koncowy += int_na_string(ilosc_zabitych);
		ilosc_przeciwnikow_wypisana = true;
		wynik_koncowy += " przeciwnikow!";
	}
	przyciski[przycisk_W] = false;
	przyciski[przycisk_A] = false;
	przyciski[przycisk_S] = false;
	przyciski[przycisk_D] = false;
	gracz1.resetuj_zegar();
	gracz1.umarl();
}


void ustaw_tekst(Text &text1, Font& czcionka,string napis_koncowy)
{
	text1.setFont(czcionka);
	text1.setString(napis_koncowy);
	text1.setFillColor(Color::Black);
	text1.setPosition(pozycjaX_gameover + 50, pozycjaY_gameover + 250);
	text1.setCharacterSize(15);

}

string int_na_string(int liczba)
{
	string chwilowy, zamieniony;
	if (liczba < 0) {
		zamieniony = "-";
		liczba = -liczba;
	}
	do {
		chwilowy += liczba % 10 + 48;
		liczba -= liczba % 10;
	} while (liczba /= 10);
	for (int i = chwilowy.size() - 1; i >= 0; i--)
		zamieniony += chwilowy[i];
	return zamieniony;
}

void test_jednostkowy(int liczba)
{
	cout << int_na_string(liczba) << endl;
}
