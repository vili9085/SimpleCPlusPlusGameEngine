#ifndef COMPONENT_H
#define COMPONENT_H
#include <string>
#include "PreyDator.h"



namespace preydator{
	class GameObject;
	class Component
	{
	public:
		virtual void tick() = 0;
		GameObject * getParent() const;
		std::string getName() const;
		
		virtual ~Component();

	protected:
		Component(GameObject * parent, std::string name);

	private:
		GameObject * parent;
		std::string name;
		Component(const Component & other) = delete;
		const Component & operator=(const Component & other) = delete;
		
	};
}
#endif // !COMPONENT_H

