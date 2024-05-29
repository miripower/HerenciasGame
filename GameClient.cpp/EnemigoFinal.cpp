#include "EnemigoFinal.h"

EnemigoFinal::EnemigoFinal(int pHp, int pAttack, std::string pName, int pPositionX, int pPositionY, int pFireAttack, int pFrozenAttack) : Personaje(pHp, pAttack, pName, pPositionX, pPositionY)
{
	fireAttack = pFireAttack;
	frozenAttack = pFrozenAttack;
}

int EnemigoFinal::getFireAttack()
{
	return fireAttack;
}

int EnemigoFinal::getFrozenAttack()
{
	return frozenAttack;
}

void EnemigoFinal::setFireAttack(int pFireAttack)
{
	fireAttack = pFireAttack;
}

void EnemigoFinal::setFrozenAttack(int pFrozenAttack)
{
	frozenAttack = pFrozenAttack;
}

int EnemigoFinal::realizarAtaque()
{
	int randAttack = rand() % 100;
	if (randAttack >= 0 && randAttack <= 4) {
		return getFireAttack();
	}
	else if (randAttack >= 5 && randAttack <= 10) {
		return getFrozenAttack();
	}
	else {
		return getAttack();
	}
}