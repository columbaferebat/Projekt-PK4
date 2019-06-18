#pragma once
#include "postac.h"
#include"generator_przeciwnikow.h"


class gracz :public postac
{
public:
	gracz();
	~gracz();
	void skacz(generator_przeciwnikow& generator);
	void bij(generator_przeciwnikow& generator,int szansa);
	gracz(Texture& plik);
	void odejmij_zycie();
	void umarl();
};
