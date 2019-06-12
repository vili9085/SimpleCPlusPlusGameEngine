#ifndef TEXT_H
#define TEXT_H
#include "GameObject.h"
#include <SDL_ttf.h>
#include <string>

namespace preydator{

	class Text : public Component
	{

		friend class GameSession;
		friend class Scene;
	public:
		
		static Text * create(GameObject * parent, int fontSize, Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::string text = "", std::string path = "BROADW.TTF");
		void setText(std::string newString);
		void editText(bool b);
		bool getEditable() const;
		std::string getText()const;
		~Text();

		

	protected:
		Text(GameObject * parent, int fontSize, Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::string text, std::string path);
		void recieveInput(SDL_Event & e);
		void tick();
		
	private:
		bool isEditable;
		TTF_Font * font = nullptr;
		SDL_Texture * textTx = nullptr;
		SDL_Color textColor{ 255,255,255,255 };
		SDL_Rect textRect;
		int fontSize;
		void loadText();
		void freeTexture();
		int width;
		int height;
		std::string text;


	};
}
#endif // !TEXT_H

