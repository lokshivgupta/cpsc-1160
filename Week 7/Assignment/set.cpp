#include "set.h"
#include<iostream>
using namespace std;

//Default constructor
template<typename T>
set<T>::set(){
    cap = 10;
    size = 0;
    data = new T[cap];
}

//Parametrized Constructor
template <typename T>
set<T>::set( T arr[], unsigned int arrSize){
    cap = arrSize + 10;
    size = 0;
    data = new T[cap];
    for(unsigned int i = 0; i < arrSize;i++){
        add(arr[i]);
    }

}
//Copy Constructor
template <typename T>
set<T>::set(const set<T>& other){
    cap = other.cap;
    size = other.size;
    data = new T[cap];
    for(unsigned int i = 0; i <size; i++){
        data[i] = other.data[i];
    }
}

//Destructor
template<typename T>
set<T>::~set(){
    delete [] data;
}

// template<typename T>
// T* set<T>::getData()const{
//     return data;
// }
template <typename T>
void set<T>::resize(){
     if(size == cap){
        cap += 10;
       
    }else if(cap - size > 10){
        cap -= 10;
        if(cap < 10){
            cap = 10;
        }
    }

    T* newData = new T[cap];
    for(unsigned int i = 0; i < size; i++){
        newData[i] = data[i];
    }
    delete [] data;
    data = newData;

}
template<typename T>
bool set<T>::add(const T& t1){
    if(size == cap){
        resize();
    }
    for(unsigned i = 0; i < size; i++){
        if(data[i] == t1){
            return false;
        }
    }

    data[size] = t1;
    ++size;
    return true;
}
template <typename T>
bool set<T>::remove(T& t1){
    for(int i = 0; i < size; i++){
        if(data[i] == t1){
            for(int j = i; j< size-1;j++){
                data[j] = data[j+1];
            }
            --size;
            return true;
        }
    }
    return false;
}
template <typename T>
bool set<T>::checkMembership(const T& t1)const{
    for(unsigned int i = 0; i < size; i++){
        if(data[i] == t1){
            return true;
        }
        
    }
    return false;
}

template <typename T>
set<T> set<T>::unionSet(const set<T>& other) const {
    set<T> result;
    for(unsigned int i = 0; i < this->size;i++){
        result.add(this->data[i]) ;
    }
    for(unsigned int i = 0; i < other.size; i++){
        result.add(other.data[i]);
    }
    return result;

}
template<typename T>
set <T> set<T>:: intersection(const set<T>& other) const{
    set<T> result;
    for(unsigned int i = 0; i < this->size;i++){
        if(other.checkMembership(this->data[i])){
            result.add(this->data[i]);
        }
    }
    return result;
}

template <typename T>
set<T> set<T>:: symmetry(const set<T>& other) const{
    set<T> result;

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
void set<T>::clear(){
    delete [] data;
    cap = 10;
    size = 0;
    data = new T[cap];
}

template<typename T>
unsigned int set<T>:: getSize()const{
    return size;
}

template<typename T>
void set<T>:: displaySet() const{
    cout << "{" ;
    for(unsigned int i = 0; i < size; i++){
        cout << data[i];
        if(i != size-1){
            cout << ",";
        }
    }
    cout << "}" << endl;
}
template <typename T>
bool set<T>::isEqual(const set<T>& other) const{
    if(size != other.size){
        return false;
    }
    for(unsigned int i = 0; i < size; i++){
        bool found = false;
        for(unsigned int j = 0; j < other.size; j++){
            if(data[i] == other.data[j]){
                found = true;
                break;
            }
        }
        if(!found){
            return false;
        }
        
    }
    return true;
}

template <typename T>
bool  set<T>::removeMin(T& other){
    if(size == 0){
        return false;
    }
    T min = data[0];
    unsigned int minIndex = 0;
    for(unsigned int i = 1;i < size; i++){
        if(data[i] < min){
            minIndex = i;
            min = data[i];
        }
    }
    other = data[minIndex];
    for(unsigned int j = minIndex; j < size -1; j++){
        data[j] = data[j + 1];
    }
    --size;
    resize();
    return true;

}
template <typename T>
bool set<T>::removeMax(T& other){
    if(size == 0){
        return false;
    }
    T max = data[0];
    unsigned int maxIndex = 0;
    for(unsigned int i = 1;i < size; i++){
        if(data[i] > max){
            maxIndex = i;
            max = data[i];
        }
    }
    other = data[maxIndex];
    for(unsigned int j = maxIndex; j < size -1; j++){
        data[j] = data[j + 1];
    }
    --size;
    resize();
    return true;
}