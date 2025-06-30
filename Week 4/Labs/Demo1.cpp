#include<string>
#include<iostream>

// Define function that calculates the average of two numbers
double getAverage(double x, double y){
   return  (x +  y )/ 2;
    
}

// Define a functon that dispalys a welcome message on the screen. The message shoudl include username
void greetUser(std:: string userName){
    std::cout << "Welcome " << userName << std:: endl;
}

// Define a functon that reads the user'name from the keyboard and dispalys a welcome message on the screen. The message shoudl include username
void greetUser(){
    std:: string userName;
    std:: getline(std:: cin, userName);
    std::cout << "Welcome " << userName << std:: endl;
}

// Define a function that calculates the results of dividing a number by another number
double divide(double x, double y) {
    if(y == 0){
        throw "Division by 0 is denied";
    }
    return x / y;
}

//Define a function that swaps the value of two integers
void swap(int& x , int& y){
    int temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 12, b = 24;
    swap(a,b);
   std:: cout << a <<b << std:: endl;
}

//Write a program that first reads the name of the user from the keyboard, anf displays a welcome message, including that name on the csreen
//the program asks the user to ener two numbersn calaculate the result of division and display it
int main1(){
     greetUser();
     std:: cout <<"Enter two numbers " << std:: endl;
     double x, y;
     std:: cin>> x >> y;
     try {
         std:: cout << "the result is "<< divide(x,y) << std:: endl;
     }catch(...) {
        std:: cout << " Something is wrong" <<std:: endl;
     }
    return 0;
}
