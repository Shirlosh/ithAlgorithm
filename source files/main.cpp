#include <iostream>
#include "Array.h"
#include "ithAlgorithms.h"
#include "operativeFuncs.h"
#include <iomanip>
#include <stdexcept>

using namespace std;

int main()
{
	int arrSize, index;

	try
	{
		arrSize = operativeFuncs::readSize();

		Array arr1(arrSize);
		index = operativeFuncs::readIndex(arrSize);

		operativeFuncs::readArray(arr1);
		Array arr2(arr1), arr3(arr1);


		cout << "Insertion sort i'th element: " << fixed << setprecision(4) << ithAlgorithms::insertionSort_RunTime(arr1, index) << endl;
		cout << "Selection i'th element: " << fixed << setprecision(4) << ithAlgorithms::selectionAlgorithm_RunTime(arr2, index) << endl;
		cout << "Quintuplet algorithm i'th element: " << fixed << setprecision(4) << ithAlgorithms::quintupleAlgorithm_RunTime(arr3, index) << endl;
	}

	catch (invalid_argument& ex) { cout << "wrong input" << endl; }
	catch (...) { "unknown error"; }

	return 0;
}