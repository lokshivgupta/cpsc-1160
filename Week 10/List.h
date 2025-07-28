#ifndef LIST_H
#define LIST_H

template<typename T>
class Node{
public:
    Node(T value){
        this->value = value;
        next = nullptr;
    }

    T value;
    Node*next;

};

template <typename T>
class List{
public:
    List(){
        head = tail = nullptr;
        size = 0;
    }
    void insertAt(int index, T value){
        if(index < 0 || index > size){
            throw"Invalid Index";
        }
        Node<T>* newNode = new Node<T>(value);
        if(index == 0){
            newNode->next = head;
            head = newNode;
            if(size == 0){
                tail = newNode;
            }
        }else{
            Node<T>* prevNode = head;
            for(int i = 0; i < index-1;++i){
                prevNode = prevNode -> next;
            }
            newNode->next = prevNode->next;
            prevNode->next = newNode;
            if(index == size){
                tail = newNode;
            }
        }
        ++size;
    }
    void pushFront(T value){
        insertAt(0,value);
    }
    void pushBack(T value){
        insertAt(size,value);
    }
    T removeFrom(int index){
    if(index < 0 || index >= size){
        throw "Invalid Index";
    }

    Node<T>* nodeToDelete = nullptr;
    T valToReturn;

    if(index == 0){
        nodeToDelete = head;
        head = head->next;
        // If the list becomes empty, update tail
        if(size == 1){
            tail = nullptr;
        }
    } else {
        Node<T>* prevNode = head;
        for(int i = 0; i < index - 1; ++i){
            prevNode = prevNode->next;
        }
        nodeToDelete = prevNode->next;
        prevNode->next = nodeToDelete->next;
        // If deleting the last node, update tail
        if(index == size - 1){
            tail = prevNode;
        }
    }

    valToReturn = nodeToDelete->value;
    delete nodeToDelete;
    --size;
    return valToReturn;
}
T removeVal(T value){
    
}

private:
    Node<T> * head, * tail;
    int size;

}
#endif