#ifndef SET_H
#define SET_H
#include <iostream>
using namespace std;

template <typename T>
class set{
public:
    set(); //default constructor
    set(T arr[], unsigned int size); //parametrized constructor
    set(const set<T>&); //copy constructor
    ~set(); //destructor
    bool add(const T&);
    bool remove(T&);
    void resize();
    bool checkMembership(const T&) const;
    set<T> unionSet(const set<T>&) const;
    set<T>  intersection(const set<T>&) const;
    set<T> symmetry(const set<T>&) const;
    void clear();
    unsigned int getSize() const;
    void displaySet() const;
    bool isEqual(const set<T>&) const;
    bool removeMin(T&);
    bool removeMax(T&);
    //T* getData() const;
    template<typename U>
    friend U* extractArray(const set<U>&);
private:
    T* data; // pointer to the data
    unsigned int cap ; // maximum capacity for the array
    unsigned int size; //size of the array

};

#endif