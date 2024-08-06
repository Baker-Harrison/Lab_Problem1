//
// Created by Harrison Baker on 8/5/24.
//
#include "../include/Picture.h"
#include "../include/Exceptions//CoordinateOutOfRangeException.h"

Picture::Picture() {
	this->width = 5;
	this->height = 5;
}


ostream &operator<<(ostream &strm, const Picture &picture) {
	for (const auto& row : picture.pixels) {
		for (const auto& elem : row) {
			strm << elem << " ";
		}
		strm << endl; // Print a new line at the end of each row
	}
	return strm;
}

Picture::Picture(int width, int height)
{
	this->width = width;
	this->height = height;


	this->pixels.resize(this->height);
	for (vector<Color> &row : this->pixels) {
		row.resize(this->width);
	}

	for (int i = 0; i < this->height; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			setPixel(j, i, Color::WHITE);
		}
	}

}

void Picture::setPixel(int x, int y, Color c) {

	try {
		if (x < 0 || x >= width || y < 0 || y >= height) {
			throw CoordinateOutOfRangeException();
		}
	}
	catch (CoordinateOutOfRangeException e)
	{
		cout << "Coordinate out of range" << endl;
	}


	pixels[y][x] = c;
}


int Picture::getWidth() const {
	return width;
}

int Picture::getHeight() const {
	return height;
}

