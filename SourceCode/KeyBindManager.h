#ifndef KEYBINDMANAGER_H
#define KEYBINDMANAGER_H
#include <unordered_map>
#include "MemKeyBind.h"

namespace preydator{
	class KeyBindManager
	{
		friend class GameSession;
	public:
		KeyBindManager();
		void bindFunctionToKey(unsigned int key, void(*funk)());
				
		template <class T>
		void bindMemberFunctionToKey(unsigned int key, T * member, void(T::*funk)()) {
			MemKeyBind <T> * keyBind = MemKeyBind<T>::create(key, member, funk);
			keyMap[keyBind->getKey()] = keyBind;
		}
		~KeyBindManager();
		
	private:
		
		KeyBind * getKeyBind(unsigned int keyToGet);
		std::unordered_map<unsigned int, KeyBind *> keyMap;
	};

	extern KeyBindManager keyBindManager;

}
#endif // !KEYBINDMANAGER_H

