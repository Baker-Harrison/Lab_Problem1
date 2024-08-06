//
// Created by thehe on 8/5/2024.
//

#ifndef LAB_PROBLEM1_COLOR_H
#define LAB_PROBLEM1_COLOR_H

#include <iostream>

using namespace std;

class Color
{
private:
    int red;
    int green;
    int blue;



public:
	Color();
    Color(int red, int green, int blue);
	const static Color RED;
	const static Color YELLOW;
	const static Color BLUE;
	const static Color GREEN;
	const static Color PURPLE;
	const static Color ORANGE;
	const static Color BLACK;
	const static Color WHITE;
	const static Color GRAY;

	friend std::ostream &operator<<(std::ostream &strm, const Color &color);

};

#endif //LAB_PROBLEM1_COLOR_H
