#include "System.h"
#include <SDL.h>
#include <SDL_image.h>

namespace Project2 {

	System::System() {
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("StarWars", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 800, 600, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		SDL_Surface* bgimage = IMG_Load("D:/Plugget/CPROG/background.bmp");
		bgTx = SDL_CreateTextureFromSurface(ren, bgimage);
		SDL_FreeSurface(bgimage);
	}

	System::~System() {
		SDL_DestroyTexture(bgTx);
		SDL_DestroyWindow(win);
		SDL_DestroyRenderer(ren);
		SDL_Quit();
	}
	System sys;

}