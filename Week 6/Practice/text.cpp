#include"text.h"
using namespace std;
Text:: Text(){
    cap = 10;
    leng = 0;
    s = new char[cap]
    id = nextId++;
Text:: Text(string strObj){
    cap = strObj.length() + 10;
    leng = strObj.length();
    s = new char[cap];
    for(int i = 0; i < leng; i++){
        s[i] = strObj[i];
    }
    id = nextId++;
}
Text:: append(const text& textObj){
    if(cap < textObj.length + leng){
        expand(textObj.length + leng);
        for(int i = lengl j = 0; j< textObj.length; i++;j++){
            s[i] = textObj.s[j];
            leng += textobj.length;
        }
    }
}
void Text:: expand(unsigned int newLength){
    if(newLength > && newLength < cap){
        cap = newLength +10;
        char *newMem = new char [cap];

        for(int i = 0; i < leng; i++){
            newMem[i] = s[i];
        }
        delete [ ] s;
        s = newMem;
    }
}
bool Text:: deleteFirst(char ch){
    int i = 0;
    for(; i < leng; i++){
        if(s[i] == ch){
            break;
        }
    }
    if(i == 0){
        return false;
    }
    for(int j = i+1; j < leng; j++){
        s[j-1] = s[j];
    }
    --leng;
    return true;
}
unsigned int Text:: getId const{
    return id;
}
//type casting conversion
Text:: Text(char c){
    cap = size + 10;
    leng = 1; s = new char[cap];
    s[0] = ch;
}
Text:: ~Text(){
    delete [] s;
    cap = 0;
    leng = 0;
    s = nullptr;

}
Text:: Text(const Text& anotherObj){
    cap = anotherObj.cap;
    leng = anotherObj.leng;
    id = nextId++;

    s = new char[cap];
    for(int i = 0; i < leng; i ++){
        s[i] = anotherObj.s[i];
    }
}

Text Text:: operator+(const Text& t2) const{
    Text result(*this);
    result.append(t2);
    return result;
}
 Text&  Text:: operator=(const Text& t2){
    if(&t2 != this){
        delete[] s;
        cap = t2.cap;
        leng = t2.leng;
        s = new char[cap];
        for(int i = 0; i < leng; i++){
            s[i] = t2.s[i];
        }
    }
    return *this;
}
char& Text:: operator[](int index){
    if(index < 0 || index >= length){
        throw"Index out of range";
    }
    return s[index];
}
}

//always check self assignment 
//release memeory at thebegining' no need to relase in copy construtcr
//copy deeply
//dont forget to return your object 

