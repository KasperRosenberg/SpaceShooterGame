#ifndef LASER_H
#define LASER_H
#include "Component.h"

namespace Project2 {
	class Laser : public Component
	{
	public:
		static Laser* getInstance(int x, int y);
		void draw() const;
		void tick();
		~Laser();
		SDL_Texture* get_texture() const { return laserTexture; }
		std::string getType() const { return type; }

	protected:
		Laser(int x, int y);

	private:
		std::string type;
		SDL_Texture* laserTexture;

	};
}

#endif

