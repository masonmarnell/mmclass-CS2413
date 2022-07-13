//Homework #6, Mason Marnell

//Implements multiple sorts including insertion sort, selection sort, bubble sort and quick sort.
//Also allows the user to input array arr within the program.

#include <iostream>
#include <array>
#include <string>

using namespace std;

int arrOG[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int arr[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; //eventually just make it to where the user inputs arr to both

//function for swapping elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void insertionsort(int arr[], int len){
    int key;
    int j;
    for (int i = 1; i < len; i++){
        key = arr[i];
        j = i-1;

        //move arr that is greater than the key +1 index pos
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}


void selectionsort(int* arr, int len) {
    int j;
    int imin;
    for (int i = 0; i < len - 1; i++) {
        imin = i;   // get min arr index
        for (j = i + 1; j < len; j++)
            if (arr[j] < arr[imin])
                imin = j;
        //swap to get in correct position
        swap(arr[i], arr[imin]);
    }
}

void bubblesort(int arr[], int len) {
    int tempint;
    for (int i = 0; i < (len - 1); i++) {
        for (int j = (len - 0); j >= (i + 1); j--) { //the pseudocode was wrong in the example but I sort of fixed it
            if (arr[j] < arr[j - 1]) {
                tempint = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tempint;
            }
        }
    }
}



// finds partition point
int partition(int arr[], int first, int last) {

    // set pivot to far right
    int pivot = arr[last];

    // points to larger element
    int i = (first - 1);

    // compare elements with pivot
    for (int j = first; j < last; j++) {
        if (arr[j] <= pivot) {
            i=i+1;

            // calls swap
            swap(&arr[i], &arr[j]);
        }
    }

    // calls swap again
    swap(&arr[i + 1], &arr[last]);
    // returns the point where partition is
    return (i + 1);
}

void quicksort(int arr[], int first, int last) {
    if (first < last) {

        // small elements go to left, large go to right of pivot
        int pi = partition(arr, first, last);

        // left of pivot recursive
        quicksort(arr, first, pi - 1);

        // right of pivot recursive
        quicksort(arr, pi + 1, last);
    }
}

int menuSwitch(int menuChoice) {

    string data;
    int dataint = 0;
    string data2;
    int data2int = 0;
    
    int size = sizeof(arr) / sizeof(arr[0]);
    int inputCounter = 0;

    switch (menuChoice) {
    case 0: //input arr
        int tempChoice;
        
        cout << "Type a value and press enter to input a number into the list." << endl;
        cout << "Insert as many values as you'd like. Enter 0 to save and return to menu: " << endl;
        cin >> tempChoice;

        while (tempChoice != 0) {
            arrOG[inputCounter] = tempChoice;
            arr[inputCounter] = tempChoice;
            inputCounter++;
            cin >> tempChoice;
        }


        break;
    case 1: //insertion sort
        insertionsort(arr, size);
        for (int i = 0; i < size; i++) {
            if (arr[i] != 0) {
                cout << arr[i] << " ";
            }
        }
        break;
    case 2: //selection sort
        selectionsort(arr, size);
        for (int i = 0; i < size; i++) {
            if (arr[i] != 0) {
                cout << arr[i] << " ";
            }
        }
        for (int i = 0; i < size; i++) { //resets array to user inputted state
            arr[i] = arrOG[i];
        }
        break;
    case 3: //bubble sort
        bubblesort(arr, size);
        for (int i = 0; i < size+1; i++) {
            if (arr[i] != 0) {
                cout << arr[i] << " ";
            }
        }
        for (int i = 0; i < size; i++) { //resets array to user inputted state
            arr[i] = arrOG[i];
        }
        break;
    case 4: //quick sort
        quicksort(arr, 0, size-1);
        for (int i = 0; i < size; i++) {
            if (arr[i] != 0) {
                cout << arr[i] << " ";
            }
        }

        for (int i = 0; i < size; i++) { //resets array to user inputted state
            arr[i] = arrOG[i];
        }
        break;
    case 5://radix sort
        cout << endl << "I almost surely remember in class that professor said we don't have to implement radix sort if we do not want the bonus. If I am wrong about this then that is unfortunate." << endl;
        break;
    case 6://exit
        exit(0);
        break;
    default:
        cout << "Pick a valid number" << endl;
        break;
    }

    return 0;
}

int menu() { //displays the menu and returns the number chosen
    int choice;
    cout << endl;
    cout << "               M E N U" << endl << endl;
    cout << "Input Data (0), Insertion Sort (1), Selection Sort (2), " << endl;
    cout << "Bubble Sort(3), Quick Sort(4), Radix Sort(5)" << endl;
    cout << "Exit Program (6)" << endl << endl << "Choose? ";
    cin >> choice;
    return choice;
}


int main() {

    while (true) { //loops indefinitely (until exit is called)
        menuSwitch(menu()); //menu() is passed in, passing an int to menuSwitch
    }

    return 0;
}


//thank you!