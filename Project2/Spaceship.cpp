#include "Spaceship.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "Laser.h"
#include "Session.h"

namespace Project2 {
	Spaceship::Spaceship(int x, int y, int w, int h): Component(x,y,w,h)
	{
		SDL_Surface* shipSurf = IMG_Load("D:/Plugget/CPROG/starwarsship.png");
		SDL_Rect shipRect = { 0,0, shipSurf->w, shipSurf->h };
		texture = SDL_CreateTextureFromSurface(sys.get_ren(), shipSurf);
		SDL_FreeSurface(shipSurf);
		type = "spaceship";
	}
	Spaceship* Spaceship::getInstance(int x, int y, int w, int h)
	{
		return new Spaceship(x, y, w, h);
	}
	void Spaceship::draw() const
	{
		SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());
	}

	void Spaceship::tick()
	{

	}

	Spaceship::~Spaceship()
	{
		SDL_DestroyTexture(texture);
	}
	void Spaceship::leftDown(const SDL_Event& event)
	{
		decreaseX();
	}
	void Spaceship::rightDown(const SDL_Event& event)
	{
		increaseX();
	}
	void Spaceship::leftUp(const SDL_Event& event)
	{
	}
	void Spaceship::rightUp(const SDL_Event& event)
	{
	}
	void Spaceship::upDown(const SDL_Event& event)
	{
		decreaseY();
	}
	void Spaceship::downDown(const SDL_Event& event)
	{
		increaseY();
	}
	void Spaceship::spaceDown(const SDL_Event& event)
	{
		Laser* l = Laser::getInstance(getRect().x + 37, getRect().y - 40);
		ses.add(l);

	}
}


