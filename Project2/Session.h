#ifndef SESSION_H
#define SESSION_H
#include <vector>
#include "Component.h"

namespace Project2 {
	class Session
	{
	public:
		void add(Component* c);
		void run();
		void remove(Component* c);
		~Session();

	private:
		std::vector<Component*> components;
		std::vector<Component*> added;
		std::vector<Component*> removed;
	};
	extern Session ses;
}

#endif

