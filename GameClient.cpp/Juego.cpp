#include "Juego.h"

void Juego::iniciarMapa(char mapa[WIDTH][HEIGHT])
{
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			mapa[i][j] = '-';
		}
	}
}

void Juego::mostrarMapa(char mapa[WIDTH][HEIGHT]) {
	for (int i = 0; i < WIDTH; i++) {
		for (int j = 0; j < HEIGHT; j++) {
			std::cout << mapa[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int Juego::randPosX() {
	int randX = rand() % WIDTH;
	return randX;
}

int Juego::randPosY() {
	int randY = rand() % HEIGHT;
	return randY;
}

void Juego::colocarPersonaje(char mapa[WIDTH][HEIGHT], Personaje& personaje, char icono) {
	int posX = personaje.getPositionX();
	int posY = personaje.getPositionY();
	mapa[posX][posY] = icono;
}

void Juego::inicioJuego() {
	std::cout << "  _    _ ______ _____  ______ _   _  _____ _____           _____ " << std::endl;
	std::cout << " | |  | |  ____|  __ \\|  ____| \\ | |/ ____|_   _|   /\\    / ____|" << std::endl;
	std::cout << " | |__| | |__  | |__) | |__  |  \\| | |      | |    /  \\  | (___  " << std::endl;
	std::cout << " |  __  |  __| |  _  /|  __| | . ` | |      | |   / /\\ \\  \\___ \\ " << std::endl;
	std::cout << " | |  | | |____| | \\ \\| |____| |\\  | |____ _| |_ / ____ \\ ____) |" << std::endl;
	std::cout << " |_|__|_|______|_|__\\_\\______|_| \\_|\\_____|_____/_/    \\_\\_____/ " << std::endl;
	std::cout << "  / ____|   /\\   |  \\/  |  ____|                                 " << std::endl;
	std::cout << " | |  __   /  \\  | \\  / | |__                                    " << std::endl;
	std::cout << " | | |_ | / /\\ \\ | |\\/| |  __|                                   " << std::endl;
	std::cout << " | |__| |/ ____ \\| |  | | |____                                  " << std::endl;
	std::cout << "  \\_____/_/    \\_\\_|_ |_|______|_  __ _          _               " << std::endl;
	std::cout << " | |           |  __ \\    | | |  \\/  (_)        | |              " << std::endl;
	std::cout << " | |__  _   _  | |__) |__ | | | \\  / |_ _ __ ___| |_             " << std::endl;
	std::cout << " | '_ \\| | | | |  ___/ _ \\| | | |\\/| | | '__/ _ \\ __|            " << std::endl;
	std::cout << " | |_) | |_| | | |  | (_) | | | |  | | | | |  __/ |_             " << std::endl;
	std::cout << " |_.__/ \\__, | |_|   \\___/|_| |_|  |_|_|_|  \\___|\\__|            " << std::endl;
	std::cout << "         __/ |                                                   " << std::endl;
	std::cout << "        |___/                                                    " << std::endl;
	system("pause");
	system("cls");
}

void Juego::finalJuego(int pHp)
{
	if (pHp > 0)
	{
		std::cout << " __     ______  _    _  __          _______ _   _ " << std::endl;
		std::cout << " \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | |" << std::endl;
		std::cout << "  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| |" << std::endl;
		std::cout << "   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` |" << std::endl;
		std::cout << "    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |" << std::endl;
		std::cout << "    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_|" << std::endl;
	}
	else
	{
		std::cout << " __     ______  _    _   _      ____   _____ ______ " << std::endl;
		std::cout << " \\ \\   / / __ \\| |  | | | |    / __ \\ / ____|  ____|" << std::endl;
		std::cout << "  \\ \\_/ / |  | | |  | | | |   | |  | | (___ | |__   " << std::endl;
		std::cout << "   \\   /| |  | | |  | | | |   | |  | |\\___ \\|  __|  " << std::endl;
		std::cout << "    | | | |__| | |__| | | |___| |__| |____) | |____ " << std::endl;
		std::cout << "    |_|  \\____/ \\____/  |______\\____/|_____/|______|" << std::endl;
	}
}
