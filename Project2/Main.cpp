#include <SDL.h>
#include "System.h"
#include "Session.h"
#include "Spaceship.h"

using namespace Project2;
	int main(int argc, char** argv) {
		Spaceship* s = Spaceship::getInstance(350, 500, 80, 70);
		ses.add(s);
		ses.run();
		return 0;
	}


