#include "GameObject.h"

#include "InputKeys.h"
#include <string>
#include <iostream>
#include <algorithm>
#include "Sprite.h" //this is needed?
#include "Collider.h"



namespace preydator{

	GameObject::GameObject() {

	}
	GameObject::GameObject(std::string name) : name(name) {

	}
	GameObject::GameObject(Vector2 startPos) : position(startPos)
	{
		
		
	}
	GameObject::GameObject(std::string name, Vector2 startPos) : name(name), position(startPos) {

	}
	
	void GameObject::addComponent(Component * component) {
		
		components.push_back(component);
	}

	Vector2 & GameObject::getPosition() {
		return position;
		
	}

	std::vector <Component *> & GameObject::getVectorOfComponents() {
		return components;
	}
	
	void GameObject::destroy(GameObject * gameObject) {
		gameObject->setDestructionFlag(true);
	}
	
	void GameObject::setDestructionFlag(bool b) {
		destructionFlag = b;
	}

	bool GameObject::getDestructionFlag() {
		return destructionFlag;
	}

	std::string GameObject::getName() {
		return name;
	}

	GameObject::~GameObject()
	{
		
		for (Component * c : components) {
			delete c;
		}
	}

	void GameObject::onCollision(Collider * other) {

	}
	void GameObject::setCollisionFlag(bool b) {
		collisionFlag = b;
	}
	bool GameObject::getCollisionFlag() {
		return collisionFlag;
	}

}
