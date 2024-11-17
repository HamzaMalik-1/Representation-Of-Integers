#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <iomanip>
using namespace std;


// ConversionFunction
string convertToDecimal(string value, int base);
string decimalToOtherBase(string value, int base);

// Functions to check input type
bool checkBinary(string value, string base);
bool checkOctal(string value, string base);
bool checkDecimal(string value, string base);
bool checkHexaDecimal(string value, string base);

string reverseString(string value);    // Function to reverse a string
int findSizeOfString(string value);    // function to find Size of String
int findPower(int base, int exponent); // Function to find power



// To find Power
int findPower(int base, int exponent)
{
    int result = 1;

    for (int counter = 1; counter <= exponent; counter = counter + 1)
    {
        result = result * base;
    }
    return result;
}

// TO find the size of string
int findSizeOfString(string value)
{
    int size = 0;
    while (value[size] != '\0')
    {
        size = size + 1;
    }
    return size;
}

// convert hexa, binary or octal to decimal
string convertToDecimal(string value, int base)
{
    string data = value;
    int exponent = 0;
    // int base = 8;
    int result = 0;
    int number = 0;
    int sizeOfString = findSizeOfString(value);

    for (int counter = sizeOfString - 1; counter >= 0; counter = counter - 1)
    {
        if (data[counter] >= '0' && data[counter] <= '9')
        {
            // why string lastDigit= data[counter]; not acceptable
            string lastDigit = "";
            lastDigit = data[counter];
            number = stoi(lastDigit);
        }
        else if (data[counter] >= 'A' && data[counter] <= 'Z')
        {
            int lastDigit = data[counter];
            number = lastDigit - 55;
        }
        result = result + (number * findPower(base, exponent));
        exponent = exponent + 1;
    }
    return to_string(result);
}

// decimal to go all other bases
string decimalToOtherBase(string value, int base)
{
    int data = stoi(value);
    string result = "";
    int remainder = 0;
    while (data != 0)
    {
        // cout << "to_string(data%base) : " << to_string(data%base)<<endl;
        remainder = data % base;
        if (remainder >= 10 && remainder <= 15)
        {
            char character = remainder + 55;
            result = result + character;
        }
        else
        {
            result = result + to_string(data % base);
        }
        data = data / base;
        // i can also find size of string here by using any counter
    }
    result = reverseString(result);
    return result;
}

// For reverse all the sring
string reverseString(string value)
{
    int sizeOfString = findSizeOfString(value);
    string result = "";
    for (int counter = sizeOfString - 1; counter >= 0; counter = counter - 1)
    {
        result = result + value[counter];
    }
    return result;
}


// Check is input is in binary form
bool checkBinary(string value, string base)
{
    int counter = 0;
    if (base != "2")
    {
        return false;
    }
    while (value[counter] != '\0')
    {
        if (value[counter] != '1' && value[counter] != '0')
        {
            return false;
        }
        counter = counter + 1;
    }
    return true;
}

// Check is input is in octal form
bool checkOctal(string value, string base)
{
    int counter = 0;
    if (base != "8")
    {
        return false;
    }
    while (value[counter] != '\0')
    {
        if (value[counter] < '0' || value[counter] > '7')
        {
            return false;
        }
        counter = counter + 1;
    }
    return true;
}

// Check is input is in decimal form
bool checkDecimal(string value, string base)
{
    int counter = 0;
    if (base != "10")
    {
        return false;
    }
    while (value[counter] != '\0')
    {
        if (value[counter] < '0' || value[counter] > '9')
        {
            return false;
        }
        counter = counter + 1;
    }
    return true;
}

// Check is input is in hexaDecimal form
bool checkHexaDecimal(string value, string base)
{
    int counter = 0;
    if (base != "16")
    {
        return false;
    }
    while (value[counter] != '\0')
    {
        if ((value[counter] < '0' || value[counter] > '9') && (value[counter] < 'A' || value[counter] > 'F'))
        {
            return false;
        }
        counter = counter + 1;
    }
    return true;
}
