#ifndef ENEMY_H
#define ENEMY_H
#include "Component.h"

namespace Project2 {
	class Enemy : public Component
	{
	public:
		static Enemy* getInstance(int x);
		void draw() const;
		void tick();
		~Enemy();
		SDL_Texture* get_texture() const { return enemyTexture; }
		std::string getType() const { return type; }

	protected:
		Enemy(int x);

	private:
		std::string type;
		SDL_Texture* enemyTexture;

	};
}

#endif