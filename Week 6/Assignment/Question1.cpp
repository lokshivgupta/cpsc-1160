#include<cstdlib>
#include<ctime>
#include<iostream>
using namespace std;

unsigned int* generateRandomList(unsigned int size){
    srand(time(NULL));

    unsigned int* list = new unsigned int [size];

    for(int i = 0; i < size; i++){
        list[i] = rand();
    }
    return list;
}

//for static array 
void generateRandomList(unsigned int list[], unsigned int size);
//for dynamic array
void generateRandomList(unsigned int* list, unsigned int size);

int main(){
    unsigned int size = 10;
    unsigned int* list = generateRandomList(size);

    cout<< "Randomly Generated Numbers: ";
    for(int i = 0; i < size; i++){
        cout << list[i] + " ";

    }
    cout << endl;

    return 0;
}