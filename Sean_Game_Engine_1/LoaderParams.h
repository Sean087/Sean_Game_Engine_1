//
//	Name:			LoaderParams.h
//
//	Description:	Class that takes values into its constructor and sets them
//					as member variables that can then be accessed to set the 
//					initial values of an object. Alleviates the need to define
//					a load() function for every class.
//

#ifndef __LoaderParams__
#define __LoaderParams__

#include <string>
#include <SDL.h>

class LoaderParams
{
public:

	LoaderParams(int x, int y, int width, int height, std::string textureID, char type)
		: 
	m_x(x), 
	m_y(y), 
	m_width(width), 
	m_height(height), 
	m_textureID(textureID),
	m_type(type)
	{
	}

	int getX() const { return m_x; }
	int getY() const { return m_y; }
	int getWidth() const { return m_width; }
	int getHeight() const { return m_height; }
	std::string getTextureID() const { return m_textureID; }
	char getType() const { return m_type; }

private:

	int m_x;
	int m_y;

	int m_width;
	int m_height;

	char m_type;

	std::string m_textureID;

};
#endif