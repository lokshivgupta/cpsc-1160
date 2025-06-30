#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <iostream>
using namespace std;

template<typename T>
class DynamicArray{
public:
    DynamicArray(unsigned int userCap = 10); //constructor
    DynamicArray(T* , unsigned int); //constructor
    DynamicArray<T>& operator=(const DynamicArray&);
    T& operator[](int); 
    DynamicArray<T> operator+(const DynamicArray&);
    DynamicArray<T> operator*(int);
    DynamicArray<T>& operator+=(const DynamicArray&);
    bool operator==(const DynamicArray<T>&)const;
    bool operator!=(const DynamicArray<T>&) const;
    bool operator!()const;
    friend ostream& operator <<(ostream& out, const DynamicArray<U>&);

private:
    T* values;
    unsigned int size;
    unsigned int cap;

};


//Constructor
template<typename T>
DynamicArray<T>:: DynamicArray(unsigned int userCap){
    if(userCap == 0){
        cap = 10;
    }else{
        cap = userCap;
    }
    size = 0;
    values = new T[cap];
}

//Constructor
template <typename T>
DynamicArray<T>:: DynamicArray(T* arr, unsigned int userSize){
    cap = userSize;
    size = userSize;
    values = new T[cap];

    for(unsigned int i = 0; i < size; i++){
        values[i] = arr[i];
    }
}

//Operator loading for =
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& da2){
    if(this == &da2){
        return *this;
    } 

    delete[] values;
    cap = da2.cap;
    size = da2.size;
    values = new T[cap];

    for(unsigned int i = 0; i < size; i++){
         values[i] = da2.values[i];
     }
    return *this;
}

//Operator overloading for []
template<typename T>
T& DynamicArray<T>::operator[](int index){
    if(index < 0 || index >= (int)size){
        throw out_of_range("Index out of range") ;
    }
    return values[index];
}

//Operator overloading for +
template<typename T>
DynamicArray<T> DynamicArray<T>::operator+(const DynamicArray& da2){
    unsigned int newSize = size + da2.size;
    DynamicArray<T> newArray(newSize);
    for(unsigned int i = 0; i < size; i++){
        newArray.values[i] = values[i];
    }
    for(unsigned int i = 0; i <da2.size; i++){
        newArray.values[size + i] = da2.values[i];
    }
    return newArray;
}

//Operator overloading for *
template<typename T>
DynamicArray<T> DynamicArray<T>::operator* (int times){
    if(times < 0){
        return DynamicArray<T>(0);
    }
    DynamicArray<T> newArray(size * times);
    for(unsigned int i =0; i < times;i++){
        for(unsigned int j = 0; j < size; j++){
            newArray.values[i * size + j] = values[j];
        }
    }  
    newArray.size = size * times;
    return newArray; 
}

//Free function overloading for *
template<typenameT>
DynamicArray<T> DynamicArray<T>::operator*(int times, const DynamicArray<T>&arr ){
    return arr * times;
}

//Operator overloading for +=
template<typename T>
DynamicArray<T>& DynamicArray:: operator+=(const DynamicArray& arr){
    unsigned int newSize = size + arr.size;
    T* newVals = new T[newSize];

    for(unsigned int i = 0; i < size; i++){
        newVals[i] = values[i];
    }

    for(unsigned int i = 0; i<arr.size; i++){
        newVals[size + i] = arr.values[i];
    }

    delete [] values;
    values = newVals;
    size = newSize;

    return *this;
}   

//Operator overloading for ==
template<typename T>
bool DynamicArray<T>::operator==(const DynamicArray<T>& arr)const{
    if(size != arr.size){
        return false;

    }
    for(unsigned int i = 0;i <size;i++){
        if(values[i] != arr.values[i]){
            return false;
        }
    }
    return true;
}

//Operator overloading for equality 
template<typename T>
bool DynamicArray<T>:: operator!=(const DynamicArray<T>& arr)const{
    return !(*this == arr);
}

//Operator overloading for inequality 
template<typename T>
bool DynamicArray<T>:: operator!()const{
    return size == 0;
}

//Operator overloading for printing
template<typename U>
ostream& DynamicArray<U>:: operator <<(ostream& out, const DynamicArray<U>&){
    out << "{";
    for (unsigned int i = 0; i < arr.size; ++i) {
        out << arr.values[i];
        if (i != arr.size - 1) {
            out << ",";
        }
    }
    out << "}";
    return out;
}
#endif