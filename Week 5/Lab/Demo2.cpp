//write a program that reads the grades of the students in a class
//and stores them in the memory

#include <iostream>
using namespace std;

const int maxSize = 300;

int main (){
    cout <<"Enter how many students: ";
    int n;
    cin >> n;


    double *grades  =  new double[n];

    //if we want to initialize it 
   // double *grades  =  new double[n]{0};
    // double grades[maxSize];
    for(int i =0; i<maxSize;i++){
        cin >> grades[i] ; // or *(grades + i)
    }
    //we are using grades
    delete[] grades;

    //examples
    int *p = new int{9};
    cout << *p <<endl; // prints 9 coz we initialized it
    delete p;
    return 0;
}