#include<iostream>
using namespace std;

void selectionSort(int list[], int size){
    for(int i  = 1; i < size; i++){
        int maxIndex = 0;
        for(int j = 0; j <= size - 1 - i;j++){
            if(list[j] > list[maxIndex]){
                maxIndex = j;
            }
        
        }
        int temp = list[maxIndex];
        list[maxIndex] = list[size - i];
        list[size - i] = temp;
    }
}