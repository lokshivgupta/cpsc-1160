#include "sortedSet.h"
#include<iostream>
using namespace std;


//Default Constructor
template <typename T>
sortedSet<T>::sortedSet(){
    cap = 10;
    size = 0;
    data = new T[cap];
    ascending = true;
}

//Destructor
template<typename T>
sortedSet<T>:: ~sortedSet(){
    delete [] data;
}

//Parametrized Constructor
template<typename T>
sortedSet<T>:: sortedSet(T arr[], unsigned int arrSize){
    cap = arrSize + 10;
    size = arrSize;
    data = new T[cap];
    ascending = true;
    for(unsigned int i = 0; i < arrSize;i++){
        add(arr[i]);
    }
}

//Copy Constructor
template<typename T>
sortedSet<T>::sortedSet(const sortedSet<T>& other){
    cap = other.cap;
    size = other.size;
    data = new T[cap];
    ascending = other.ascending;
    for(unsigned int i = 0; i < size; i++){
        data[i] = other.data[i];
    }
}

//Resize method
template<typename T>
void sortedSet<T>::resize(){
    if(size == cap){
     cap += 10;
       
    }else if(cap - size > 10){
        cap -= 10;
        if(cap < 10){
            cap = 10;
        }
    }
    T* newData = new T[cap];
    for(unsigned int i = 0; i < cap;i++){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

template<typename T>
bool sortedSet<T>::add(const T& val){
    if(checkMembership(val)){
        return false;
    }
    if(size == cap){
        resize();
    }

    int i = size - 1;
    if(ascending){
        while(i >= 0 && data[i] > val){
            data[i + 1] = data[i];
            i--;
        }
    }else {
        while(i >= 0 && data[i] < val){
            data[i + 1] = data[i];
            i--;
        }
    }
    data[i + 1] = val;
    size++;
    return true;
}
template<typename T>
bool sortedSet<T>::remove(T& val){
    for(unsigned int i = 0; i < size; i++){
        if(data[i] == val){
            for(unsigned int j = i; j < size - 1; j++){
                data[j] = data[j + 1];
            }
            size--;
            resize();
            return true;
        }
    }
    return false;
}

template<typename T>
bool sortedSet<T>::checkMembership(const T& val) const {
    for(unsigned int i = 0; i < size; i++){
        if(data[i] == val){
            return true;
        }
    }
    return false;
}

template<typename T>
sortedSet<T> sortedSet<T>::unionSet(const sortedSet<T>& other) const {
    sortedSet<T> result;
    for(unsigned int i = 0; i < size; i++){
        result.add(data[i]);
    }
    for(unsigned int i = 0; i < other.size; i++){
        result.add(other.data[i]);
    }
    return result;
}

template<typename T>
void sortedSet<T>::reverseOrder(){
    ascending = !ascending;
    for(unsigned int i = 0; i < size / 2; i++){
        T temp = data[i];
        data[i] = data[size - i - 1];
        data[size - i - 1] = temp;
    }
}

template<typename T>
sortedSet<T> sortedSet<T>:: intersection(const sortedSet<T>& other) const {
    sortedSet<T> result;
    result.ascending = ascending;
    for(unsigned int i = 0; i < size; i++){
        if(other.checkMembership(data[i])){
            result.add(data[i]);
        }
    }
}

template<typename T>
sortedSet<T> sortedSet<T>:: symmetry(const sortedSet<T>& other) const{
    sortedSet<T> result;
    result.ascending = ascending;
    for(unsigned int i = 0; i < size; i++){
        if(!(other.checkMembership(data[i]))){
            result.add(data[i]);
        }
    }
     for(unsigned int i = 0; i < other.size; i++){
         if(!(other.checkMembership(data[i]))){
             result.add(other.data[i]);
         }
     }
    return result;
}

template<typename T>
void sortedSet<T>:: clear(){
    delete [] data;
    cap = 10;
    size = 0;
    data = new T[cap];
}

template<typename T>
unsigned int sortedSet<T>:: getSize()const{
    return size;
}

template<typename T>
void sortedSet<T>:: displaySet()const{
    cout << "{" ;
    for(unsigned int i = 0; i < size; i++){
        cout << data[i];
        if(i != size-1){
            cout << ",";
        }
    }
    cout << "}" << endl;
}

template<typename T>
bool sortedSet<T>:: isEqual(const sortedSet<T>& other)const{
    if(size != other.size || ascending != other.ascending){
        return false;
    }
    for(unsigned int i = 0; i < size; i ++){
        if(data[i] != other.data[i]){
            return false;
        }
    }
    return true;
}

template<typename T>
bool sortedSet<T>:: removeMin(T& val){
    if(size === 0){
        return false;
    }
    unsigned int minIndex;
    if(ascending){
        minIndex = 0;
    }else{
        minIndex = size - 1;
    }

    val = data[minIndex];
    for(unsigned int i = 0; i < size - 1; i++){
        data[i] = data[i +1];
    }
    size = size - 1;
    resize();
    return true;
}

template<typename T>
bool sortedSet<T>:: removeMax(T& val){
    if(size === 0){
        return false;
    }
    unsigned int maxIndex;

    if(ascending){
        maxIndex = size - 1;

    }else{
        maxIndex = 0;
    }
    val = data[maxIndex];

    for(unsigned int i = 0; i < size - 1; i++){
        data[i] = data[i +1];
    }
    size = size - 1;
    resize();
    return true;

}


