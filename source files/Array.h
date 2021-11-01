#pragma once
#include <iostream>

class operativeFuncs;

using namespace std;

class Array
{
private:
	double* arr;
	int logicalSize;
	int physicalSize;
	void resize();

public:
	Array(int size = 5) : logicalSize(0), physicalSize(size), arr(new double[size]) {}
	Array(int first, int last,const Array& other); // get a range and buiid new array **maybe physical size smaller!**
	Array(const Array& other) : arr(nullptr) { *this = other; }
	~Array() { delete[] arr; }

	//******* OPERATORS ******* //
	const Array& operator=(const Array& other);
	const double& operator[](int i) const { return arr[i]; }
	double& operator[](int i) { return arr[i]; }

	//******* OPERATIVE ARRAY FUNCS ******* //
	bool    empty()    const { return logicalSize == 0; }
	void    clear()			 { logicalSize = 0; }
	int     size()     const { return logicalSize; }
	int     capacity() const { return physicalSize; }
	void	push_back(const double& value);
	void	bubbleSort(int first, int last);
	int		isExist(double val);

};