#ifndef SPACESHIP_H
#define SPACESHIP_H
#include "Component.h"
#include <SDL.h>

namespace Project2 {
	class Spaceship: public Component
	{
	public: 
		static Spaceship* getInstance(int x, int y, int w, int h);
		void draw() const;
		void tick();
		~Spaceship();
		SDL_Texture* get_texture() const { return texture; }
		void leftDown(const SDL_Event& event);
		void rightDown(const SDL_Event& event);
		void leftUp(const SDL_Event& event);
		void rightUp(const SDL_Event& event);
		void upDown(const SDL_Event& event);
		void downDown(const SDL_Event& event);
		void spaceDown(const SDL_Event& event);
		std::string getType() const { return type; }
	protected:
		Spaceship(int x, int y, int w, int h);

	private:
		std::string type;
		SDL_Texture* texture;
	};
}

#endif
