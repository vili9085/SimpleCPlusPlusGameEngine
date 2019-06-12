#ifndef STARTTEXT2_H
#define STARTTEXT2_H

#include "GameObject.h"
#include "Text.h"

using namespace preydator;
class StartText2 : public GameObject {
public:
	using GameObject::GameObject;
	StartText2();

	void init();
	void update();

	~StartText2();

private:
	Text * myText;
};

#endif /* StartText2_hpp */
