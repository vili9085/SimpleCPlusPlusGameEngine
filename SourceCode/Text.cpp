#include "Text.h"
#include <iostream>


namespace preydator {


	Text::Text(GameObject * parent, int fontSize, Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::string text, std::string path) : Component(parent, "Text"), fontSize(fontSize), textColor{ r, g, b, a }, text(text), font(TTF_OpenFont(path.c_str(), fontSize))
	{
		if (font == nullptr) {
			ErrorLog::printError(TTF_GetError() + getName());
			
		}
		loadText();

	}
	void Text::loadText() {
		freeTexture();

		SDL_Surface * tempSurface = TTF_RenderText_Solid(font, text.c_str(), textColor);

		if (tempSurface == nullptr) {
			ErrorLog::printError(SDL_GetError() + getName());
			return;
		}
		else {

			textTx = SDL_CreateTextureFromSurface(preyDator.getRenderer(), tempSurface);
			if (textTx == nullptr) {
				ErrorLog::printError(SDL_GetError());
				return;
			}
			else {
				TTF_SizeText(font, text.c_str(), &width, &height);
				textRect = { 0, 0, width, height };
				SDL_FreeSurface(tempSurface);

			}

		}
		
	}

	void Text::freeTexture() {

		if (textTx != nullptr) {
			SDL_DestroyTexture(textTx);
			textTx = nullptr;
			width = 0;
			height = 0;
			textRect = { 0,0,0,0 };
		}
	}


	Text::~Text()
	{
		SDL_DestroyTexture(textTx);
	}

	void Text::tick() {
		
		textRect.x = getParent()->position.x - textRect.w / 2;
		textRect.y = getParent()->position.y;
		SDL_SetRenderDrawColor(preyDator.getRenderer(), textColor.r, textColor.g, textColor.b, textColor.a);
		//SDL_RenderDrawRect(preyDator.getRenderer(), &textRect);
		SDL_RenderCopy(preyDator.getRenderer(), textTx, nullptr, &textRect);

	}
	

	void Text::setText(std::string newText) {
		text = newText;
		loadText();
	}

	
	void Text::recieveInput(SDL_Event & e) {
	
		text += e.text.text;
		loadText();

	}

	std::string Text::getText() const {
		return text;
	}

	void Text::editText(bool b) {
		isEditable = b;
	}

	bool Text::getEditable() const {
		return isEditable;
	}

	Text * Text::create(GameObject * parent, int fontSize, Uint8 r, Uint8 g, Uint8 b, Uint8 a, std::string text, std::string path) {
		return new Text(parent, fontSize, r, g, b, a, text, path);
	}

}
