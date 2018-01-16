//
//	LoadTileTexture.h
//
//

#ifndef __LoadTileTexture__
#define __LoadTileTexture__

#include <SDL_image.h>
#include <string>

class LoadTileTexture
{
public:
	//Initializes variables
	LoadTileTexture();

	//Deallocates memory
	~LoadTileTexture();

	//Loads image at specified path
	bool loadFromFile(std::string path, SDL_Renderer *rend);

#ifdef _SDL_TTF_H
	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(int x, int y, SDL_Renderer *rend, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};
#endif