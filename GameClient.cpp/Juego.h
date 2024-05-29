#pragma once
#include "Personaje.h"

const int width = 15;
const int height = 15;

class Juego
{
public:
	char mapa[width][height];
	static void iniciarMapa();
	static void mostrarMapa();
};