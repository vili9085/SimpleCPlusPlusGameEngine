#include "Component.h"
#include <iostream>


namespace preydator{
	
	Component::Component(GameObject * parent, std::string name) : parent(parent), name(name)
	{
		
	}

	Component::~Component()
	{
		
	}

	GameObject * Component::getParent() const {
		return parent;
	}

	std::string Component::getName() const {
		return name;
	}

	
}
