#include "Enemy.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "Session.h"

namespace Project2 {

    Enemy::Enemy(int x) : Component(x, 0, 50, 50) {
        SDL_Surface* enemySurf = IMG_Load("D:/Plugget/CPROG/anakin.png");
        SDL_Rect enemyRect = { 0,0, enemySurf->w, enemySurf->h };
        enemyTexture = SDL_CreateTextureFromSurface(sys.get_ren(), enemySurf);
        SDL_FreeSurface(enemySurf);
        type = "enemy";
    }

    Enemy* Enemy::getInstance(int x)
    {
        return new Enemy(x);
    }

    void Enemy::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), enemyTexture, NULL, &getRect());
    }

    void Enemy::tick() {
        if (getRect().y >= 550) {
            ses.remove(this);
        }
        else {
            increaseEnemyY();
        }
    }

    Project2::Enemy::~Enemy()
    {
        SDL_DestroyTexture(enemyTexture);
    }
}
