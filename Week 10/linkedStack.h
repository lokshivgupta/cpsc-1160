#include<iostream>
using namespace std;

#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
template<typename T>
struct Node{ // or class
     T value;
     Node* next;
    Node(T v){
        value = v;
        next = nullptr;
    } //parametrized constructor;

    

}
template <typename T>
class LinkedStack{
public:
    LinkedStack(){
        size = 0;
        top = nullptr;
    }
    void push(T value){
        Node<T>* newNode = new Node<T>(value);
        newNode->next = top;
        top = newNode;
        ++size;

    }
    T pop(){
        if(top === nullptr){
            throw "Stack Underflow";
        }
        T valueToReturn = top->value;
        Node<T>* toDelete = top;
        top = top->next; // or toDelete->next
        delete toDelete;
        --size;
        return valueToReturn;

    }
private:
    Node<T>* top;
    unsigned int size;
}

#endif