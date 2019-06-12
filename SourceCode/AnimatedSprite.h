#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H
#include "Sprite.h"
#include <vector>

namespace preydator{
	class AnimatedSprite : public Sprite
	{
		friend class GameSession;
		friend class Scene;
	public:

		static AnimatedSprite * create(GameObject * parent, std::string path, int horizontalPics, int verticalPics);
		void loadSprite(std::string path);
		int getWidth() const;
		int getHeight() const;
		
		~AnimatedSprite();

	protected:
		AnimatedSprite(GameObject * parent, std::string path, int horizontalPics, int verticalPics);

	private:
		void tick();
		std::vector<SDL_Rect> animClips; 
		void setRects();
		int frame = 0;
		int horizontalPics;
		int verticalPics;
		int noOfClips;

	};
}

#endif // !ANIMATEDSPRITE_H

