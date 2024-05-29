#pragma once
#include "Personaje.h"

const int WIDTH = 10;
const int HEIGHT = 20;

class Juego
{
public:
	static void iniciarMapa(char mapa[WIDTH][HEIGHT]);
	static void mostrarMapa(char mapa[WIDTH][HEIGHT]);
	static int randPosX();
	static int randPosY();
	static void colocarPersonaje(char mapa[WIDTH][HEIGHT], Personaje& personaje, char icono);
	static void inicioJuego();
};
