#include <iostream>
using namespace std;

#ifndef QUEUE_H
#define QUEUE_H 

template <typename T, int CAP>
//const int CAP = 10;
class Queue {
public:
    Queue(); //default contructor 
    void enqueue(const T& value); // Add an element to the end of the queue
    T dequeue(); // Remove and return the front element of the queue
    unsigned int getSize() const; // Get the number of elements in the queue
    bool isEmpty() const; // Check if the queue is empty
    bool isFull() const; // Check if the queue is full
    
    //Queue(const Queue&) = delete; // Disable copy constructor
private:
    T q[CAP]; // Array to hold the queue elements
    int front; // Index of the front element
    int rear; // Index of the rear element
    

    void expand(); // Function to expand the queue capacity
}

template <typename T, int CAP>
Queue<T, CAP>::Queue() {
    front = 0;
    rear = 0;
    
}

template <typename T, int CAP>
void Queue<T, CAP>::enqueue(const T& value) {
    if(isFull()){
        throw "Queue Overflow";
    }

    q[rear] = value;
    if(rear < CAP - 1){
        rear++;
    } else {
        rear = 0; // Wrap around if we reach the end of the array
    } //or rear = (rear + 1) % CAP;


}

template <typename T, int CAP>
T Queue<T, CAP>::dequeue() {
    if(isEmpty()){
        throw "Queue Underflow";
    }  

     T value = q[front];
     front = (front + 1) % CAP; // Wrap around if we reach the end of the array
     //or //if(front < CAP - 1){
     //    front++;
     //} else {
     //    front = 0;
     //}
     return value;
 }
 template <typename T, int CAP>
unsigned int Queue<T, CAP>::getSize() const {
    if(rear >= front) {
        return rear - front; // Normal case
    } else {
        return CAP - front + rear; // Wrap around case
    }
    //or //return (rear + CAP - front) % CAP;
}

 template <typename T, int CAP>
bool Queue<T, CAP>::isEmpty() const {
    return front == rear;
}   

 template <typename T, int CAP>
bool Queue<T, CAP>::isFull() const {
    return (rear + 1) % CAP == front; // Check if the next position of rear is front
}   

template <typename T, int CAP>
void Queue<T, CAP>::expand() {
    
    T* temp = new T[cap * 2];
    int j = 0;
    // Copy elements from the current queue to the new array
   for(int i = front; i != rear; i = (i+1 )% cap,j++){
    temp[j] = q[i];
   }
   delete[] q;
   q = temp;
   cap *= 2;
   rear = j;
   front = 0;
}   