#include "Array.h"
#include "operativeFuncs.h"

Array::Array(int first, int last, const Array& other) : logicalSize(0), physicalSize(other.physicalSize),
														arr(new double[last - first + 1])
{
	for (int i = first, j = 0; i <= last; i++, j++)
	{
		arr[j] = other.arr[i];
		logicalSize++;
	}
}

const Array& Array::operator=(const Array& other)
{
	if (this != &other) {
		logicalSize = other.logicalSize;
		physicalSize = other.physicalSize;

		delete[] arr;
		arr = new double[logicalSize];
		
		for (int i = 0; i < logicalSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

void Array::push_back(const double& value) 
{
	if (logicalSize == physicalSize)
		resize();
	arr[logicalSize++] = value;
}

void Array::bubbleSort(int first, int last)
{

	for (int i = first; i < last; i++)
	{
		for (int j = first; j < last; j++)
		{
			if (arr[j] > arr[j + 1])
				operativeFuncs::swap(arr[j], arr[j + 1]);
		}
	}
}

int Array::isExist(double val)
{
	for (int i = 0; i < logicalSize; i++)
	{
		if (arr[i] == val)
			return i;
	}
	return -1;
}


void Array::resize()
{
	physicalSize *= 2;
	double* temp = new double[physicalSize];
	for (int i = 0; i < logicalSize; i++)
		temp[i] = arr[i];

	delete[] arr;
	arr = temp;
}


