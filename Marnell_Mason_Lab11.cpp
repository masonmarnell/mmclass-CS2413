//Data Structures Lab 11 - Mason Marnell

//This program implements merge sort in c++. The example array was hard coded in the main function, but any array could be used.

#include <iostream>

using namespace std;

//function to merge the subarrays
void merge(int data[], int first, int mid, int last){ //found it was easier to pass in the mid value
    int subArr1 = mid - first + 1;
    int subArr2 = last - mid;

    // temporary arrays
    int* leftArr = new int[subArr1];
    int* rightArr = new int[subArr2];

    // copy arrays
    for (int i = 0; i < subArr1; i++)
        leftArr[i] = data[first + i];
    for (int i = 0; i < subArr2; i++)
        rightArr[i] = data[mid + 1 + i];
    int subArr1Index = 0;
    int subArr2Index = 0;
    int mergedIndex = first;

    // merge temp arrays
    while (subArr1Index < subArr1 && subArr2Index < subArr2) {
        if (leftArr[subArr1Index] <= rightArr[subArr2Index]) {
            data[mergedIndex] = leftArr[subArr1Index];
            subArr1Index=subArr1Index+1;
        }
        else {
            data[mergedIndex] = rightArr[subArr2Index];
            subArr2Index=subArr2Index+1;
        }
        mergedIndex=mergedIndex+1;
    }
    
    // get straglers from first
    while (subArr1Index < subArr1){
        data[mergedIndex] = leftArr[subArr1Index];
        subArr1Index=subArr1Index+1;
        mergedIndex=mergedIndex+1;
    }
    // get straglers from last
    while (subArr2Index < subArr2){
        data[mergedIndex] = rightArr[subArr2Index];
        subArr2Index=subArr2Index+1;
        mergedIndex=subArr2Index+1;
    }
}

//recursively splits into subarrays then merges
void mergeSort(int data[], int first, int last){
    if (first >= last)
        return;
    int mid = (first + last) / 2;
    mergeSort(data, first, mid);
    mergeSort(data, mid + 1, last);
    merge(data, first, mid, last);
}

void main(){
    int myArray[] = { 23,16,30,7,9,48,15 }; //example array in the slides
    int size = sizeof(myArray) / sizeof(myArray[0]); //easiest way I could find to get length of the array

    cout << "Original array is: ";
    for (int i = 0; i < size; i++){
        cout << myArray[i] << " ";
    }

    mergeSort(myArray, 0, size - 1);

    cout << endl << endl << "Sorted array is: ";
    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }

    return;
}

// thank you :)