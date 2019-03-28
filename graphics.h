#pragma once
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <SDL.h>
#include <map>
#include <string>





class Graphics {
public:
	Graphics();
	~Graphics();

	//load image into _spriteSheets if it's not already there. 
	//Every image is only loaded once. Returns that image from the map.
	SDL_Surface* loadImage(const std::string &filePath);

	//overlap texture pulled from teh sprite sheet onto a particular part of the screen
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);


	//push the render to the screen
	void flip();

	//cleares te screen
	void clear();

	SDL_Renderer* getRenderer() const;

private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;
	
	std::map<std::string, SDL_Surface*> _spriteSheets;

};



#endif
