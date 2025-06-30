#include "sortedSet.h"
#include<iostream>
using namespace std;

template <typename T>
sortedSet<T>::sortedSet(){
    cap = 10;
    size = 0;
    data = new T[cap];
    ascending = true;
}
template<typename T>
sortedSet<T>:: ~sortedSet(){
    delete [] data;
}
template<typename T>
sortedSet<T>:: sortedSet(T arr[], unsigned int arrSize){
    cap = size + 10;
    size = arrSize;
    data = new T[cap];
    ascending = true;
    for(unsigned int i = 0; i < arrSize;i++){
        add(arr[i]);
    }
}

