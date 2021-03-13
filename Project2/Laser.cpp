#include "Laser.h"
#include <SDL.h>
#include <SDL_image.h>
#include "System.h"
#include "Session.h"

namespace Project2 {

    Laser::Laser(int x, int y) : Component(x, y, 10, 50) {
        SDL_Surface* laserSurf = IMG_Load("D:/Plugget/CPROG/laser.png");
        SDL_Rect laserRect = { 0,0, laserSurf->w, laserSurf->h };
        laserTexture = SDL_CreateTextureFromSurface(sys.get_ren(), laserSurf);
        SDL_FreeSurface(laserSurf);
        type = "laser";
    }

    Laser* Laser::getInstance(int x, int y)
    {
        return new Laser(x,y);
    }

    void Project2::Laser::draw() const
    {
        SDL_RenderCopy(sys.get_ren(), laserTexture, NULL, &getRect());
    }

    void Laser::tick() {
        if (getRect().y <= 0) {
            ses.remove(this);
        }
        else {
            decreaseLaserY();
        }
    }

    Project2::Laser::~Laser()
    {
        SDL_DestroyTexture(laserTexture);
    }
}
