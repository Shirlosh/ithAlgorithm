#pragma once
#include "Array.h"
#include "operativeFuncs.h"

class ithAlgorithms
{
private:
   static double insertionSort(Array& arr,int index);
   static double Selection(Array& arr, int left, int right, int index);
   static double quintupleAlgorithm(Array& arr, int index);


public:
    static double insertionSort_RunTime(Array& arr, int index);
    static double selectionAlgorithm_RunTime(Array& arr, int index);
    static double quintupleAlgorithm_RunTime(Array& arr, int index);


    //******* I'TH ALGORITEMS ADDONS ******* //
    int static Partition(Array& arr, int left, int right, double pivot);
};

