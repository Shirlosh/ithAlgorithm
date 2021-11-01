#pragma once
#include "Array.h"
#include <stdexcept>
#include <math.h>

enum TYPE { INTEGER, DOUBLE };

class operativeFuncs
{
public:
	// ******* READ INPUT ******* //
	static int readIndex(int size); //returns index in integer
	static void readArray(Array& arr);
	static int readSize();
	
	// ******* OTHER FUNCS ******* //
	template <class T>
	static void swap(T& x, T& y) 
	{
		T temp = x;
		x = y;
		y = temp;
	}

	static void takePivotLeft(int left, double pivot,Array& arr);
	static int Median(int first, int last);

private:
	
	static double readNumber(TYPE type);
	//static int readInteger();
	inline static bool isWhole(double num) { return num - (int)num; }
};

