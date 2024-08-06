#include <iostream>
#include "include/Color.h"
#include "include/Picture.h"
#include <fstream>
#include "include/Exceptions/FileNotFoundException.h"
#include "include/Exceptions/ColorVectorOutOfRangeException.h"
#include "include/Exceptions/ColorFileFormatException.h"

using namespace std;

int main() {
    Color color1 = Color::RED;
    Color color2 = Color::PURPLE;

    ifstream file;

    Picture picture(5, 5);

    try {
        file.open("C:/Users/thehe/CLionProjects/CPP/Lab-Problem1/ColorVector.txt");

        if (!(file.is_open())) {
            throw FileNotFoundException();
        }
    } catch (FileNotFoundException e) {
        cout << "File not found" << endl;
        return 1;
    }

    bool isOutOfRange;
    while (file) {
        int new_X;
        int new_Y;
        int newRed;
        int newGreen;
        int newBlue;

        try {
            if (!(file >> new_X >> new_Y >> newRed >> newGreen >> newBlue)) {
                if (file.eof()) {
                    break;  // End of file reached
                }
                cout << "File format is incorrect: missing values." << endl;
                throw ColorFileFormatException();
            }
        } catch (ColorFileFormatException& e) {
            return 1;  // Exit the program if file format is incorrect
        }

        isOutOfRange = false;  // Reset the flag for each new set of values

        if (newRed < 0) {
            cout << "X: " << new_X << " Y: " << new_Y << " Red Value too low: min : 0, actual: " << newRed << endl;
            isOutOfRange = true;
        } else if (newRed > 255) {
            cout << "X: " << new_X << " Y: " << new_Y << " Red Value too high: max : 255, actual: " << newRed << endl;
            isOutOfRange = true;
        }

        if (newGreen < 0) {
            cout << "X: " << new_X << " Y: " << new_Y << " Green Value too low: min : 0, actual: " << newGreen << endl;
            isOutOfRange = true;
        } else if (newGreen > 255) {
            cout << "X: " << new_X << " Y: " << new_Y << " Green Value too high: max : 255, actual: " << newGreen << endl;
            isOutOfRange = true;
        }

        if (newBlue < 0) {
            cout << "X: " << new_X << " Y: " << new_Y << " Blue Value too low: min : 0, actual: " << newBlue << endl;
            isOutOfRange = true;
        } else if (newBlue > 255) {
            cout << "X: " << new_X << " Y: " << new_Y << " Blue Value too high: max : 255, actual: " << newBlue << endl;
            isOutOfRange = true;
        }

        try {
            if (isOutOfRange) {
                throw ColorVectorOutOfRangeException();
            } else {
                picture.setPixel(new_X, new_Y, Color(newRed, newGreen, newBlue));
            }
        } catch (ColorVectorOutOfRangeException& e) {
            // Handle the exception if needed
        }
    }

    file.close();
    cout << picture;

    return 0;
}
