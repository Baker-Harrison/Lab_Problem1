//
// Created by thehe on 8/5/2024.
//

#include "../include/Color.h"

Color::Color()
{

}

Color::Color(int red, int green, int blue) {
    this->red = red;
    this->green = green;
    this->blue = blue;
}

const Color Color::RED = Color(255, 0, 0);
const Color Color::YELLOW = Color(255, 255, 0);
const Color Color::BLUE = Color(0, 0, 255);
const Color Color::GREEN = Color(0, 255, 0);
const Color Color::PURPLE = Color(150, 0, 255);
const Color Color::ORANGE = Color(255, 150, 0);
const Color Color::BLACK = Color(0, 0, 0);
const Color Color::WHITE = Color(255, 255, 255);
const Color Color::GRAY = Color(150, 150, 150);


// TODO: fix the purple part so it prints "P"
std::ostream &operator<<(std::ostream &strm, const Color &color) {

	if (color.red > color.green && color.red > color.blue)
	{
		strm << " R ";
	}
	else if (color.blue > color.green && color.blue > color.red)
	{
		strm << " B ";
	}
	else if(color.green > color.red && color.green > color.blue)
	{
		strm << " V ";
	}
	else if (color.red > color.green && color.blue > color.green)
	{
		strm << " P ";
	}
	else if (color.red > color.blue && color.green > color.blue)
	{
		strm << " Y ";
	}
	else if (color.blue > color.red && color.green > color.red)
	{
		strm << " T ";
	}
	else if (color.red == color.blue && color.blue == color.green & color.red > 250)
	{
		strm << " W ";
	}
	else if (color.red == color.blue && color.blue == color.green && color.red < 50)
	{
		strm << " D ";
	}
	else if (color.red == color.blue && color.blue == color.green && color.red >= 50 && color.red <= 250)
	{
		strm << " G ";
	}

	return strm;
}

