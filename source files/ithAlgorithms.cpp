#include "ithAlgorithms.h"
#include <ctime>
#include <chrono>
#include <fstream>
#include <iomanip>

double ithAlgorithms::insertionSort(Array& arr, int index)
{
	for (int i = 1; i < arr.size(); i++)
	{
		double curItem = arr[i];
		int j = i - 1;

		while (curItem < arr[j] && j >= 0)
		{
			arr[j + 1] = arr[j]; // move the greater element one position up to make space for the current item
			j--;
		}
		arr[j + 1] = curItem; // insert the requested item to the correct place when it found.
	}

	return arr[index-1];
}

double ithAlgorithms::Selection(Array& arr, int left, int right, int index)
{
	int pivot;

	pivot = Partition(arr, left, right,arr[left]);
	int leftPartSize = pivot - left + 1;

	if (index == leftPartSize)
		return arr[pivot];

	else if (index < leftPartSize)
		return Selection(arr, left, pivot - 1, index);
	else
		return Selection(arr, pivot + 1, right, index - leftPartSize);
}

double ithAlgorithms::quintupleAlgorithm(Array& arr, int index)
{
	int size = arr.size();

	if (size <= 5)
	{
		arr.bubbleSort(0, size-1);
		return arr[index-1];
	}

	Array MediansArr((size+4)/5);  //fifth size and ceiling 

	for (int i = 0; i < size; i += 5) // creation of the medians array
	{
		int first = i, last = i + 4;
		if (last > size - 1)
			last = size - 1;
		
		arr.bubbleSort(first,last);
		int median = operativeFuncs::Median(first, last);
		MediansArr.push_back(arr[median]);
	}

	// find the median of the MediansArray
	double pivot = quintupleAlgorithm(MediansArr, MediansArr.size()/2); //find the median
	int k = Partition(arr, 0, arr.size()-1,pivot);

	if (index == k + 1) //k's index starts from 0 while the input index starts from 1
		return pivot;
	
	//recus left subarray
	else if (index < k + 1)
	{
		Array leftSubarray(0,k-1, arr);
		return quintupleAlgorithm(leftSubarray, index);
	}
	//recurs right subarray
	else
	{
		Array rightSubarray(k + 1, size-1, arr);
		return quintupleAlgorithm(rightSubarray, index - k - 1); // right subarray and index = index - k
	}
}

double ithAlgorithms::insertionSort_RunTime(Array& arr, int index)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	double res = insertionSort(arr,index);
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;

	ofstream myfile("Measure.txt",ios::trunc);
	myfile << "Time taken by function <insertionSort> is : " << fixed << time_taken << setprecision(9);

	myfile << " sec" << endl;
	myfile.close();

	return res;
}

double ithAlgorithms::selectionAlgorithm_RunTime(Array& arr, int index)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	double res = Selection(arr, 0, arr.size() - 1, index);
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;

	ofstream myfile("Measure.txt", ios::app);
	myfile << "Time taken by function <Selection> is : " << fixed << time_taken << setprecision(9);

	myfile << " sec" << endl;
	myfile.close();

	return res;
}

double ithAlgorithms::quintupleAlgorithm_RunTime(Array& arr, int index)
{
	auto start = chrono::high_resolution_clock::now();
	// unsync the I/O of C and C++.
	ios_base::sync_with_stdio(false);

	double res = quintupleAlgorithm(arr, index);
	auto end = chrono::high_resolution_clock::now();

	// Calculating total time taken by the program.
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	time_taken *= 1e-9;

	ofstream myfile("Measure.txt", ios::app);
	myfile << "Time taken by function <QuintupleAlg> is : " << fixed << time_taken << setprecision(9);

	myfile << " sec" << endl;
	myfile.close();

	return res;
}

int ithAlgorithms::Partition(Array& arr, int left, int right, double pivot)
{
	int i = right;
	operativeFuncs::takePivotLeft(left, pivot, arr);
	int p = left;
	
	while(p!=i)
	{
		if (p < i)
		{
			if (arr[p] < arr[i])
				i--;
			else
			{
				operativeFuncs::swap(arr[p], arr[i]); // class name written to prevent implicit call to stl swap
				operativeFuncs::swap(p, i);
				i++;
			}
		}
		else // i < p
		{
			if (arr[i] < arr[p])
				i++;
			else
			{
				operativeFuncs::swap(arr[p], arr[i]);
				operativeFuncs::swap(p, i);
				i--;
			}
		}
	}

	return p;
}