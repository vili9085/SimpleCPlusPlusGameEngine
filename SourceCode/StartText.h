#ifndef STARTTEXT_H
#define STARTTEXT_H

#include "GameObject.h"
#include "Text.h"

using namespace preydator;
class StartText : public GameObject {
public:
	using GameObject::GameObject;
	StartText();

	void init();
	void update();

	~StartText();

private:
	Text * myText;
};

#endif /* StartText_hpp */

