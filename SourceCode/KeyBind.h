#ifndef KEYBIND_H
#define KEYBIND_H
#include <SDL.h>

namespace preydator{
	
	class KeyBind
	{
		friend class GameSession;
	public:
		
		static KeyBind * create(unsigned int key, void(*funk)());
		virtual ~KeyBind();
		
	protected:
		KeyBind(){}
		KeyBind(unsigned int key, void(*funk)() ) : key(key), pointToFunction(funk){}
		
	private:
		virtual void perform();
		unsigned int getKey()const;
		void(*pointToFunction)();
		unsigned int key;
		
		
		
	};
}
#endif // !KEYBIND_H

