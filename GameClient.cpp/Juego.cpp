#include "Juego.h"

Juego::Juego()
{
    iniciarMapa();
}

void Juego::iniciarMapa()
{
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            mapa[i][j] = '-';
        }
    }
}

void Juego::mostrarMapa()
{
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            std::cout << mapa[i][j];
        }
        std::cout << std::endl;
    }
}

