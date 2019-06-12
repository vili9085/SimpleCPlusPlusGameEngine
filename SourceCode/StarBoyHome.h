#ifndef STARBOYHOME_H
#define STARBOYHOME_H


#include "GameObject.h"
using namespace preydator;
class StarBoyHome : public GameObject
{
	using GameObject::GameObject;
public:
	void update();
	void init();
	void onCollision(Collider * other);
	StarBoyHome();
	~StarBoyHome();
	void setTextVisible();

private:
	AnimatedSprite * starBoySprite;
	BoxCollider * collider;
	Text * winText;
	
};
#endif // !STARBOYHOME_H

