#ifndef STARBOY_H
#define STARBOY_H
#include "GameObject.h"
using namespace preydator;
class StarBoy : public GameObject
{
	using GameObject::GameObject;
public:
	StarBoy();
	void update();
	void init();
	void onCollision(Collider * other);
	~StarBoy();

private:
	AnimatedSprite * starBoySprite;
	BoxCollider * collider;
	Physics * physics;
	float countDown = 0;
	float countDownTime = 5.0f;
	bool startCountDown = false;
	
};

#endif // !STARBOY_H

