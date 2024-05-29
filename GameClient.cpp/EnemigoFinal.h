#pragma once
#include "Personaje.h"

class EnemigoFinal : public Personaje
{
private:
	int fireAttack;
	int frozenAttack;

public:
	//Constructor:
	EnemigoFinal(int pHp, int pAttack, std::string pName, int pPositionX, int pPositionY, int pFireAttack, int pFrozenAttack);

	//Getters:
	int getFireAttack();
	int getFrozenAttack();

	//Setters:
	void setFireAttack(int pFireAttack);
	void setFrozenAttack(int pFrozenAttack);
};