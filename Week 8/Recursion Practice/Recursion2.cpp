#include<iostream>
using namespace std;


int main (){
    //Linera serach
   int mylist[] = {1,34,2,24,29};
   int key = 96;

   for(int i = 0; i < 5; i++){
    if(mylist[i] == key){
        return true;
    }
   }
   return false;
}