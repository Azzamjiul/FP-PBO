#pragma once
#include "Mobil.h"

class Pemain :
	public Mobil
{
public:
	Pemain(int x, int y);
	~Pemain();
	void LoadMobil();
	void Tubrukan();
	void UpScore();
	long long int score;
	bool isNubruk;
};

