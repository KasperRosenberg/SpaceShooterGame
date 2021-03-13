#include "Session.h"
#include <SDL.h>
#include "System.h"
#include "Enemy.h"
#include <iostream>
#include <SDL_image.h>

namespace Project2 {
#define FPS 80

	void Session::add(Component* c)
	{
		added.push_back(c);
	}
	void Session::remove(Component* c)
	{
		removed.push_back(c);
	}

	void Session::run()
	{
		bool quit = false;
		Uint32 tickInterval = 1000 / FPS;
		while (!quit) {
			Uint32 nextTick = SDL_GetTicks() + tickInterval;
			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					quit = true;
					break;
				case SDL_KEYDOWN:
					switch (event.key.keysym.sym) {
					case SDLK_LEFT:
						for (Component* c : components) {
							c->leftDown(event);
						}
						break;
					case SDLK_RIGHT:
						for (Component* c : components) {
							c->rightDown(event);
						}
						break;
					case SDLK_SPACE:
						for (Component* c : components) {
							c->spaceDown(event);
						}
						break;
					case SDLK_UP:
						for (Component* c : components) {
							c->upDown(event);
						}
						break;
					case SDLK_DOWN:
						for (Component* c : components) {
							c->downDown(event);
						}
					}
				}//Switch
			}//inre while
			for (Component* c : components) {
				c->tick();
			}

			for (Component* c : added) {
				components.push_back(c);
				added.clear();
			}
			for (Component* c : removed) {
				for (std::vector<Component*>::iterator i = components.begin(); i != components.end();) {
					if (*i == c) {
						i = components.erase(i);
					} 
					else {
						i++;
					}
				}
			}
			SDL_RenderClear(sys.get_ren());
			SDL_RenderCopy(sys.get_ren(), sys.get_texture(), NULL, NULL);
			for (Component* c : components) {
				c->draw();
			}
			SDL_RenderPresent(sys.get_ren());
			int delay = nextTick - SDL_GetTicks();
			if (delay > 0) {
				SDL_Delay(delay);
			}
			if (SDL_GetTicks() % 100 == 0) {
				Enemy* e = Enemy::getInstance((1 + (std::rand() % (800 - 1 + 1))));
				ses.components.push_back(e);
			}

			for (Component* c : components) {
				if (c->getType() == "enemy") {
					for (Component* a : components) {
						if (a->getType() != "enemy") {
							if (SDL_HasIntersection(&c->getRect(), &a->getRect())) {
								if (a->getType() == "spaceship") {
									SDL_Delay(1000);
									SDL_Surface* gameOver = IMG_Load("D:/Plugget/CPROG/gameover3.png");
									SDL_Rect gameOverRect = { 0, 0, gameOver->w, gameOver->h };
									SDL_Texture* goTx = SDL_CreateTextureFromSurface(sys.get_ren(), gameOver);
									SDL_FreeSurface(gameOver);
									SDL_RenderCopy(sys.get_ren(), goTx, NULL, NULL );
									SDL_RenderPresent(sys.get_ren());
									SDL_Delay(1000);
									quit = true;
								}
								remove(c);
								remove(a);
							}
						}

					}
				}
			}
			
		}//yttre while
	}
	Session ses;

	Project2::Session::~Session()
	{

	}
}

