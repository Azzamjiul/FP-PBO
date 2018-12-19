#pragma once
#include "Mobil.h"
class Pemain :
	public Mobil
{
public:
	Pemain();
	~Pemain();
	void Right();
	void Bottom();
	void Left();
	void Up();
};

