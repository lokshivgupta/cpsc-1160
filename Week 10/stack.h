template<typename T>
class Stack{
    public:
        Stack(); //Default constructor which creates an empty stack with the inittial cap of 10
        ~Stack();
        void push(const T& value);
        T pop();
        T peek()const;
        unsigned int getSize()const;
        bool isEmpty() const;

    private:
        T* s;
        int top; //The index of the top of the stack
        unsigned int cap;
        void expand();

};
//Default Constructor O(1)
template<typename T>
Stack<T>:: Stack(){
    cap = 10;
    top = - 1;
    s = new T[cap];

}
template <typename T>
Stack<T>:: ~Stack(){ //O(1)
    delete [] s;
    cap = 0;
    top = - 1;
    s = nullptr;
}
template<typename T>
void Stack<T>:: push(const T& value){ //O(1)
    if(top == cap - 1){
        expand()
    }
    s[++top] = value;
}
template<typename T>
T Stack<T>:: pop(){ //O(1)
    if(isEmpty()){
        throw "Stack Underflow Error";
    }
  
    return s[top--];
}
template<typename T>
T Stack<T>:: peek()const{ //O(1)
    if(isEmpty()){
        throw "Stack Underflow Error";
    }
    return s[top];
}
template<typename T>
unsigned int Stack<T>:: getSize() const{//O(1)
    return top + 1;
}
template <typename T>
bool Stack<T>:: isEmpty()const{//O(1)
    return getSize() == 0;
}
template <typename T>
void Stack<T>:: expand(){ //O(n)
    cap *= 2;
    T* newBlock = new T[cap];
    for(unsigned int i = 0; i <= top; i++){
        newBlock[i] = s[i];
    }
    delete [] s;

    s = newBlock;
}

//Overall time complexity is O(n)