#include "KeyBind.h"

namespace preydator {

	
	
	KeyBind::~KeyBind()
	{
	}

	KeyBind * KeyBind::create(unsigned int key, void(*funk)()) {
		return new KeyBind(key, funk);
	}

	unsigned int KeyBind::getKey() const {
		return key;
	}


	void KeyBind::perform() {

		pointToFunction();

	}
	


	
}