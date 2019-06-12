#ifndef FLOOR_H
#define FLOOR_H
#include "GameObject.h"



using namespace preydator;

	class Floor : public GameObject
	{
		using GameObject::GameObject;
	public:
		Floor();
		~Floor();

		void init();
		void update();
	};
#endif // !FLOOR_H

