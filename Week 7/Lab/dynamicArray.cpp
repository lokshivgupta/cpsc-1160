#include "DynamicArray.h"
#include <iostream>
using namespace std;

int main(){
    DynamicArray<int> arr1(5);
    arr1[0] = 1;
    arr1[1] = 2;
    arr1[2] = 3;
    arr1[3] = 4;
    arr1[4] = 5;

    int arr2[] = {6,7,8};
    DynamicArray<int>arr2(arr2, 3);

    //Testing += operator
    arr1 += arr2;
    cout << "Array after += :" << arr1 << endl;

    //Testing + operator
    DynamicArray<int> arr3 =  arr1+arr2;
    cout << "Array after + :" << arr3 << endl;
    
    //Testing free function 
    DynamicArray<int> arr4 = arr1 * 3;
    cout <<"Array after * :" << arr4 << endl;

    //Testing equality 
    if(arr1 == arr2){
        cout << "Arrays are equal" << endl;
    }else {
        cout << "Arrays are not equal" <<endl;
    }

    //Testing inequality
    if(arr1!=arr2){
        cout << "Array 1 and 2 are not equal "<< endl;
    }else{
        cout << "Arrays 1 and 2 are equal" << endl;
    }

    //Testing ! operator
    if(!arr1){
        cout << "Array 1 is empty" << endl;
    }else{
        cout << "Array 1 is not empty" <<endl;
    }

    //Testing = 
    DynamicArray<int> arr5 = arr1;
    //Testing []
    cout << "Arr[5] " << arr5[3] = 5 << endl;

    //Testing <<
    cout << "Printing the array 1: " << arr1 << endl;
    
    return 0;
}
