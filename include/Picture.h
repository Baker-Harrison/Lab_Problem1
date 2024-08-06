/*
Picture
	TODO: Picture should hold a 2D vector of colors.  Picture should have a constructor that takes in a width and height and sets all the colors to white.  Also have a setPixel(x: int, y: int, c: Color):void function that sets the appropriate member of the 2D array to c.  Include the getHeight():int and getWidth():int functions that returns the two dimensions of your 2D vector.
	TODO: Override the << operator in picture to display the picture by displaying each of the Colors in their appropriate location in the image.
*/

//
// Created by Harrison Baker on 8/5/24.
//

#ifndef LAB_PROBLEM1_PICTURE_H
#define LAB_PROBLEM1_PICTURE_H


#include <vector>
#include "Color.h"

class Picture: exception
{
private:
	vector<vector<Color>> pixels;
	int width{};
	int height{};

public:
	Picture();
	Picture(int width, int height);
	void setPixel(int x, int y, Color c);
	int getWidth() const;
	int getHeight() const;

	friend ostream &operator<<(ostream &os, const Picture &picture);
};

#endif //LAB_PROBLEM1_PICTURE_H
