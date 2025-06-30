#include<iostream>
using namespace std;

 int* createCopy(const int arr[], int size){
    int* dynamicArray = new int[size];
    for(int i = 0; i < size; i++){
        dynamicArray[i] = arr[i];
    }
    return dynamicArray;
}