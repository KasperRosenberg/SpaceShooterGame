#ifndef COMPONENT_H
#define COMPONENT_H
#include <SDL.h>
#include <string>
namespace Project2 {
	class Component
	{
	public:
		virtual ~Component();
		virtual void draw() const = 0;
		virtual void tick() = 0;
		virtual void leftDown(const SDL_Event&) {}
		virtual void rightDown(const SDL_Event&) {}
		virtual void spaceDown(const SDL_Event&) {}
		virtual void leftUp(const SDL_Event&) {}
		virtual void rightUp(const SDL_Event&) {}
		virtual void spaceUp(const SDL_Event&) {}
		virtual void upDown(const SDL_Event&) {}
		virtual void downDown(const SDL_Event&) {}
		const SDL_Rect& getRect() const { return rect; }

		void decreaseX(){
		rect.x -= 10;
		}
		void increaseX() {
			rect.x += 10;
		}

		void decreaseY() {
			rect.y -= 10;
		}

		void increaseY() {
			rect.y += 10;
		}

		void decreaseLaserY() {
			rect.y--;
		}

		void increaseEnemyY() {
			rect.y++;
		}

		virtual std::string getType() const = 0;

	protected:
		//Protected gör att det inte går att object av den, men subklasser kan avända den.
		Component(int x, int y, int w, int h);

	private:
		SDL_Rect rect;
		std::string type;
		//Förbjuder assignment och kopiering
		Component(const Component&) = delete;
		const Component& operator=(const Component&) = delete;
	};
}
#endif


