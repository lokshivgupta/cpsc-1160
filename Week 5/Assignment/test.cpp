#include <iostream>
#include "Assignmen3.h" 
#include <cstdlib>       
#include <ctime>  
using namespace std;

int main (){
    string a = "ABCD";
    string reversed = reverse(a);
    cout<< "Original String: " << a <<endl;
    cout<<"Reversed: "<<reversed<<endl;

    string str1 = "Hello, Welcome to CPSC 1160";
    string capital = capitalization(str1);
    cout<<"Original String: "<<str1<<endl;
    cout<<"Capital String: "<<capital<<endl;

    int num[] = {2,5,7,8,9};
    int min, max;
    findMinMax( num, 5,min, max);
    cout<<"Min: "<< min<<"Max: "<<max<<endl;

    string arr2[] = {"hello", "world", "goodbye"};
    capitalizeArrayString(arr2, 3);
    cout << "Capitalized array: ";
    for (int i = 0; i < 3; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl << endl;

    int matrix[4][10] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 1, 2},
        {1, 2, 3, 4}
    };

    bool result = areEqual(matrix, 4, 4);
    if (result)
        cout << "First and last rows are equal." << endl;
    else
        cout << "First and last rows are not equal." << endl;
     cout << endl;

     const int size = 10;
     int orignal[size] = {1,2,3,4,4,5,6,7,8,9};
     int shuffled[size];

     shuffleArray(orignal, shuffled, size);
     cout << "Shuffled Array: "<<endl;
     for (int i = 0; i < size; i++) {
        cout << shuffled[i] << " ";
    }
    cout << endl;
    

    return 0;
}