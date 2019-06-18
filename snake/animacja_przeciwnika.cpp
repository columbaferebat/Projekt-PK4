#include "animacja_przeciwnika.h"



animacja_przeciwnika::animacja_przeciwnika()
{
}


animacja_przeciwnika::~animacja_przeciwnika()
{
}
animacja_przeciwnika::animacja_przeciwnika(std::map<nazwy_textur, Texture>& kontener,int rodzaj_przeciwnika)
{
	if (rodzaj_przeciwnika == rodzajpomagier)
	{
		this->bij = kontener.find(pomagier_bije)->second;
		this->biegnij[0] = kontener.find(pomagier_biegnie1)->second;
		this->biegnij[1] = kontener.find(pomagier_biegnie2)->second;
		this->biegnij[2] = kontener.find(pomagier_biegnie3)->second;
		this->stoj = kontener.find(pomagier_stoi)->second;
		this->lez = kontener.find(pomagier_lezy)->second;
	}
	else if (rodzaj_przeciwnika == rodzajboss)
	{
		this->bij = kontener.find(boss_bije)->second;
		this->biegnij[0] = kontener.find(boss_biegnie1)->second;
		this->biegnij[1] = kontener.find(boss_biegnie2)->second;
		this->biegnij[2] = kontener.find(boss_biegnie3)->second;
		this->stoj = kontener.find(boss_stoi)->second;
		this->lez = kontener.find(boss_lezy)->second;
	}
	else 
	{
		this->bij = kontener.find(rakieta_wybucha)->second;
		this->biegnij[0] = kontener.find(rakieta_leci1)->second;
		this->biegnij[1] = kontener.find(rakieta_leci2)->second;
		this->biegnij[2] = kontener.find(rakieta_leci3)->second;
		this->stoj = kontener.find(rakieta_wybucha)->second;
		this->lez = kontener.find(rakieta_wybucha)->second;
	}
}
Texture *animacja_przeciwnika::pobierz_Texture_bij()
{
	return &(this->bij);
}
Texture *animacja_przeciwnika::pobierz_Texture_stoj()
{
	return &(this->stoj);
}
Texture *animacja_przeciwnika::pobierz_Texture_lez()
{
	return &(this->lez);
}
Texture *animacja_przeciwnika::pobierz_Texture_biegnij()
{
	return (this->biegnij);
}
void animacja_przeciwnika::animuj(generator_przeciwnikow& generator,int i,gracz& gracz1, int& ilosc_zabitych)
{
	int aktualny_stan = generator.pobierz_z_vectora(i)->get()->jaki_stan();
	if (generator.pobierz_z_vectora(i)->get()->ile_zycia() < 1)
	{
		generator.pobierz_z_vectora(i)->get()->ustaw_stan(stan_lez);
	}
	if (generator.pobierz_z_vectora(i)->get()->jaki_rodzaj_przeciwnika() != rodzajrakieta)
	{
		if (aktualny_stan == stan_lez)
		{
			if (generator.pobierz_z_vectora(i)->get()->lez(lez) == true)
			{
				ilosc_zabitych++;
				generator.usun_z_vectora(i);
			}
		}
		else if (aktualny_stan == stan_bij)
		{
			generator.pobierz_z_vectora(i)->get()->bij(bij, stoj);
			if (generator.pobierz_z_vectora(i)->get()->ile_na_zegarze() == 0&&gracz1.jaki_stan()!=stan_skacz)
			{
				gracz1.odejmij_zycie();
			}
		}

		else if (aktualny_stan == stan_biegnij)
		{
			generator.pobierz_z_vectora(i)->get()->biegnij(biegnij);
		}
		else if (aktualny_stan == stan_stoj)
		{
			generator.pobierz_z_vectora(i)->get()->stoj(stoj);
		}
	}
	else 
	{
		if (aktualny_stan == stan_biegnij)
		{
			generator.pobierz_z_vectora(i)->get()->lec(biegnij[pierwsza_textura],gracz1.jaki_stan(),gracz1.ile_na_zegarze());
		}
		else if (aktualny_stan == stan_bij)
		{
			if (generator.pobierz_z_vectora(i)->get()->ile_na_zegarze() == 0)
			{
				gracz1.odejmij_zycie();
			}
			if (generator.pobierz_z_vectora(i)->get()->wybuch(bij) == true)
			{
				generator.usun_z_vectora(i);
			}
		}
	}
}
