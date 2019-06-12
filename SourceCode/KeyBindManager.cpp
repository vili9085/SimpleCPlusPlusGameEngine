#include "KeyBindManager.h"


namespace preydator {

	KeyBindManager::KeyBindManager()
	{
	}

	void KeyBindManager::bindFunctionToKey(unsigned int key, void (*funk)()) {
		KeyBind * k = KeyBind::create(key, funk);
		keyMap[key] = k;

	}

	KeyBind * KeyBindManager::getKeyBind(unsigned int keyToGet)  {
		
		std::unordered_map<unsigned int, KeyBind*>::iterator it = keyMap.find(keyToGet);
		if (it != keyMap.end()) {
			return it->second;
		}
		return nullptr;
	}


	KeyBindManager::~KeyBindManager()
	{
		for (std::unordered_map<unsigned int, KeyBind*>::iterator it = keyMap.begin(); it != keyMap.end(); it++) {
			delete it->second;
			it = keyMap.erase(it);
		}
	}

	KeyBindManager keyBindManager;
}
