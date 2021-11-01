#include "operativeFuncs.h"

int operativeFuncs::readIndex(int size)
{
    //int index = readInteger();
    int index = (int)readNumber(INTEGER);

    if (index > size)
        throw invalid_argument("");

    return index;
}

void operativeFuncs::readArray(Array &arr)
{
    int size = arr.capacity();
    double input;

    for (int i = 0; i < size; i++) 
    {
        input = readNumber(DOUBLE);   
        arr.push_back(input);
    }
}

int operativeFuncs::readSize()
{
    int size = (int)readNumber(INTEGER);
    if (size <= 0)
        throw invalid_argument("");

    return size;
}
//
//int operativeFuncs::readInteger()
//{
//    char ch;
//    int integer = 0;
//    bool negative = false;
//
//    cin.get(ch);
//
//    if (ch == '-') 
//    {
//        negative = true;
//        cin.get(ch);
//    }
//    
//    while (ch != '\n')
//    {
//        ch -= '0';
//
//        if (ch < 0 || ch > 9)
//            throw invalid_argument("");
//
//        integer *= 10;
//        integer += ch;
//
//        cin.get(ch);
//    }
//
//    if (negative == true)
//    {
//        integer *= -1;
//        negative == false;
//    }
//
//    return integer;
//}

double operativeFuncs::readNumber(TYPE type)
{
    char ch;
    double val = 0;
    int counter = 0;
    bool alreadyPointed = false;
    bool negative = false;

    cin.get(ch);

    if (ch == '-')
    {
        negative = true;
        cin.get(ch);
    }

    while (ch != '\n' && ch !=' ') // reading the digits in a loop
    {
        //encounter a floating point
        if (ch == '.' && !alreadyPointed && type == DOUBLE)
        {
            alreadyPointed = true; //mark the next following scans are in the right of the point
            cin.get(ch);
            continue;
        }

        ch -= '0'; 
        if (ch < 0 || ch > 9) //check if its a digit
            throw invalid_argument("");

        val *= 10;
        val += ch;

        if (alreadyPointed) // if we are on the right side of the point count the digits and check if there are more then 4
        {
            counter++;
            if (counter > 4)
                throw invalid_argument("");
        } 

        cin.get(ch);
    }

    if (counter == 0 && type == DOUBLE) // if there no numbers on the right side (need at least one)
        throw invalid_argument("");

    if (negative == true) // changes to negative
    {
        val *= -1;
        negative = false;
    }

    if (type == DOUBLE)   //returns the value considering the float point
        return val / pow(10, counter);

    else                 // returns the value as is(no floating point)
        return val;
}

void operativeFuncs::takePivotLeft(int left, double pivot, Array& arr)
{
    if (arr[left] != pivot)
    {
        int p = arr.isExist(pivot);
        swap(arr[p], arr[left]);
    }
}

int operativeFuncs::Median(int first, int last)
{
    if (first == last)
        return first;
    else 
        return (last - first + 1) / 2 + first;
}
