#include <iostream>
#include "include/Color.h"
#include "include/Picture.h"
#include <fstream>
#include "include/Exceptions/FileNotFoundException.h"
#include "include/Exceptions/ColorVectorOutOfRangeException.h"

using namespace std;

int main() {
	Color color1 = Color::RED;
	Color color2 = Color::PURPLE;

	ifstream file;

	Picture picture (5, 5);




	try
	{
		file.open("/Users/harrisonbaker/CLionProjects/Lab_Problem1/ColorVector.txt");

		if (!(file.is_open()))
		{
			throw FileNotFoundException();
		}
	}
	catch(FileNotFoundException e)
	{
		cout << "File not found" << endl;
	}


	bool isOutOfRange;
	while (file)
	{
		int new_X;
		int new_Y;
		int newRed;
		int newGreen;
		int newBlue;


		file >> new_X >> new_Y;


		file >> newRed;
		if (newRed < 0)
		{
			cout << "X: " << new_X << " Y: " << new_Y << " Red Value too low: min : 0, actual: " << newRed << endl;
			isOutOfRange = true;
		}
		else if (newRed > 255)
		{
			cout << "X: " << new_X << " Y: " << new_Y << " Red Value too high: max : 255, actual: " << newRed << endl;
			isOutOfRange = true;
		}

		file >> newGreen;
		if (newGreen < 0)
		{
			cout << "X: " << new_X << " Y: " << new_Y << " Green Value too low: min : 0, actual: " << newRed << endl;
			isOutOfRange = true;
		}
		else if (newGreen > 255)
		{
			cout << "X: " << new_X << " Y: " << new_Y << " Green Value too high: max : 255, actual: " << newRed << endl;
			isOutOfRange = true;
		}
		file >> newBlue;
		if (newBlue < 0)
		{
			cout << "X: " << new_X << " Y: " << new_Y << " Blue Value too low: min : 0, actual: " << newRed << endl;
			isOutOfRange = true;
		}
		else if (newBlue > 255)
		{
			cout << "X: " << new_X << " Y: " << new_Y << " Blue Value too high: max : 255, actual: " << newRed << endl;
			isOutOfRange = true;
		}



		try {
			if (isOutOfRange)
			{
				throw ColorVectorOutOfRangeException();
			}
			else {
				picture.setPixel(new_X, new_Y, Color(newRed, newGreen, newBlue));
			}
		}
		catch (ColorVectorOutOfRangeException e)
		{

		}



	}
	picture.setPixel(0, 1, Color::BLUE);
	cout << picture<< endl;







    return 0;


}
