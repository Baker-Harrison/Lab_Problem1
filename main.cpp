#include <iostream>
#include "include/Color.h"
#include "include/Picture.h"
#include <fstream>
#include "include/Exceptions/FileNotFoundException.h"
#include "include/Exceptions/ColorVectorOutOfRangeException.h"
#include "include/Exceptions/ColorFileFormatException.h"




using namespace std;

void printDetails(int new_X,
                  int new_Y,
                  int newRed,
                  int newGreen,
                  int newBlue);

int main() {
	Color color1 = Color::RED;
	Color color2 = Color::PURPLE;

	ifstream file;

	Picture picture (5, 5);




	try
	{
		file.open("C:/Users/thehe/CLionProjects/CPP/Lab-Problem1/ColorVector.txt");

		if (!(file.is_open()))
		{
			throw FileNotFoundException();
		}
	}
	catch(FileNotFoundException e)
	{
		cout << "File not found" << endl;
	}

    int new_X;
    int new_Y;
    int newRed;
    int newGreen;
    int newBlue;
	bool isOutOfRange;
    bool hasCorrectFileFormat;
	while (file)
	{
        if (file.eof())
        {
            break;
        }
        hasCorrectFileFormat = true;


        if (file >> new_X && file >> new_Y && file >> newRed && file >> newGreen && file >> newBlue)
        {
            cout << "1" << endl;
            printDetails(new_X, new_Y, newRed, newGreen, newBlue);
        }
        else
        {
            hasCorrectFileFormat = false;
            cout << "2" << endl;
        }

        try
        {

            if (!hasCorrectFileFormat)
            {

                throw ColorFileFormatException();
            }
        }
        catch (ColorFileFormatException e)
        {
            cout << "File format incorrect: missing values" << endl;
            return -1;
        }

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
    cout << picture;







    return 0;


}

void printDetails(int new_X,
int new_Y,
int newRed,
int newGreen,
int newBlue)
{
    cout << new_X << " " << new_Y << " " << newRed << " " << newGreen << " " << newBlue << endl;
 }
