#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>

namespace Project2 {
	
	class System
	{
	public: 
		System();
		~System();

		SDL_Renderer* get_ren() const {return ren; }
		SDL_Texture* get_texture() const { return bgTx; }

	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		SDL_Texture* bgTx;

	};
	extern System sys;
}
#endif
