#include<iostream>
using namespace std;
//For calculating up till n - 1
int sumList(const int list [], int size){
    if(size == 0){
        throw "Error";
    }

    if(size == 1){
        return list[0];
    }

    int s0 = sumList( list , size - 1 );
    return s0 + list[size-1];
}

//for calculating of half
int sumListH( int list [], int size){
    if(size == 0){
        throw "Error";
    }

    if(size == 1){
        return list[0];
    }

    int mid = size / 2;
    int s0 = sumListH(list, size / 2);
    int s1 = sumListH(list + mid, size - mid);
    return s0 + s1;
}

//To find the max from the array of int
 int findMax(const int list[], int size){
    
    if(size == 0){
        throw "Error";
    }

    if(size == 1){
        return list[0];
    }

    int max1 = findMax(list, size - 1);
    if(max1 > list[size - 1]){
        return max1;
    }else{
        return list[size - 1];
    }
 }

  //Define a recursive function to display the values
 //of a list of integers in the reverse order on the screen
 void printList(const int list[], int size){
    // if(size == 0){
    //     return;
    // }
    // if(size == 1){
    //     cout << list[0] << " ";
    //     return;
    // }
    if(size >=1){
        cout << list[size - 1] << " ";
        printList(list, size - 1);
    }


 }

 //Define a recursive function that reevrses the order of values in an array
template<typename T>
void reverseArray(T list [], int size){
    // if(size == 0){
    //     throw "Error";
    // }
    // if(size == 1){
    //     return list[0];
    // }
    if(size < 1){
        return;
    }

    if(size > 1){
        T temp = list[0];
        list[0] = list[size - 1];
        list[size - 1] = temp;
    }

    reverseArray(list + 1, size - 2);
    
}

//defining linear search in recursive method
//compare the key with the first element 
//if equal return else call the function

int recursiveLinearSearch(const int list[], int size, int key, int startIndex ){
    if(size == 0){
        return -1;
    }
 
     if(list[startIndex] == key){
         return startIndex;
    }
    return recursiveLinearSearch(list, size -1, key,startIndex + 1 );
    
}   

int linearSearch(const int list[], int n, int key){
    recursiveLinearSearch(list,n,key,0);
}

//defining a recusrively binary search
int binarySearch(const int list[], int startIndex, int endIndex, int key){
    if(startIndex > endIndex){
        return -1;
    }
    int midIndex = (startIndex + endIndex)/2;
    if(key == list[midIndex]){
        return midIndex;
    }
    if(key < list[midIndex]){
        return binarySearch(list,startIndex, midIndex - 1, key);
    }
    return binarySearch(list, midIndex + 1, endIndex, key);
}

//Hanoi Tower Examples
//solved using divide and conquer
void hanoiTower(int n, string from, string to, string temp){
    if(n == 1){
        cout << "MOve disk " << n << "from " << from << " to " << to << endl;

    }
    else if(n > 1){
        hanoiTower(n - 1, from, temp, to);
         cout << "MOve disk " << n << "from " << from << " to " << to << endl;
        hanoiTower(n-1, temp, to, from);
    }
}

 int main(){
    int mylist[] = {1,2,7,8,9,19,14};
    cout << "sum: " << sumList(mylist,7 ) << endl;
    cout << "Max: " << findMax(mylist, 7)<<endl;;
    cout << "sum: " << sumListH(mylist,7 ) << endl;
    cout << "print: " ;
    printList(mylist,7 ) ;
    cout << endl;

    //int myList[] = {1,34,2,43,28};
    for(int i : mylist){
        cout << i << ' ';
    }

    reverseArray(mylist, 5);
    cout << endl;

    for (int i : mylist){
        cout << i << ' ';

    }
    return 0;

 }

