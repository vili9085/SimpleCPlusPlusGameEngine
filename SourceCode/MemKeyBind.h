#ifndef MEMKEYBIND_H
#define MEMKEYBIND_H

#include "KeyBind.h"

namespace preydator{
	template <class T>
	class MemKeyBind : public KeyBind

	{
		friend class GameSession;
		friend class KeyBindManager;
		public:
					
			static MemKeyBind* create(unsigned int key, T * member, void(T::*funk)()) {
				return new MemKeyBind<T>(key, member, funk);
			}
			

			~MemKeyBind(){}

		protected:
			
			MemKeyBind(unsigned int key, T * member, void(T::*funk)()) : key (key), member(member), pointToMemberFunction(funk) {}

		private:
			void perform() {
				(member->*pointToMemberFunction)();
			}
			unsigned int getKey() const {
				return key;
			}
			
			unsigned int key;
			void(T::*pointToMemberFunction)();
			T * member;
	
	};

}

#endif // !MEMKEYBIND_H

