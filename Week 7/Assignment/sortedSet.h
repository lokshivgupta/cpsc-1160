#ifndef SORTEDSET_H
#define SORTEDSET_H
#include <iostream>
using namespace std;


template <typename T>
class sortedSet{
    public: 
         sortedSet();  //Default Constructor
         ~sortedSet(); //destrcutor
         sortedSet(T arr[], unsigned int size); //parametrized constructor
         sortedSet(const sortedSet<T>&); //copy constructor
         void reverseOrder();
         bool add(const T&);
         bool remove(T&);
         void resize();
         bool checkMembership(const T&) const;
         sortedSet<T> unionSet(const sortedSet<T>&) const;
         sortedSet<T>  intersection(const sortedSet<T>&) const;
         sortedSet<T> symmetry(const sortedSet<T>&) const;
         void clear();
         unsigned int getSize() const;
         void displaySet() const;
         bool isEqual(const sortedSet<T>&) const;
         bool removeMin(T&);
         bool removeMax(T&);
    private:
         T* data; // pointer to the data
         unsigned int cap ; // maximum capacity for the array
         unsigned int size; //size of the array
         bool ascending;

};

#endif
