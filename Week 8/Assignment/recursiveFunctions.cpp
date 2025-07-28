#include<iostream>
#include<string>
using namespace std;

int compareStrings(const string str1, const string str2, int index){
    if(index> str1.length() && index >  str2.length()){
        return 0;
    }
    char ch1;
    if(index < str1.length()){
        ch1 = str1[index];
    }
    char ch2;
    if(index < str2.length()){
        ch2 = str2[index];
    }
    if(ch1 != ch2){
        return ch1 - ch2;
    }
    return compareStrings(str1, str2, index + 1);
}
int compareStrings(const string str1, const string str2){
    return compareStrings(str1, str2, 0);
}
bool isPalindrome(const string str1, int start, int end);
bool isPalindrome(const string str1){
    return isPalindrome(str1, 0, str1.length()-1);
}

bool isPalindrome(const string str1,int  start, int end){
    if(start>= end){
        return true;
    }
    if(str1[start] != str1[end]){
        return false;
    }
    return isPalindrome(str1,  start + 1, end-1);
}

 
bool isAscending(const int arr[], int size, int index){
    if(index >= size - 1){
        return true;
    }
    if(arr[index] > arr[index + 1]){
        return false;
    }
    return isAscending(arr,size, index + 1);
}

bool isAscending(const int arr[], int size){
    return isAscending(arr, size,0);
}
void insertVal(int arr[], int size, int val, int index){
    if(index == size || arr[index] > val){
        for(int i = size; i > index; i--){
            arr[i] = arr[i - 1];
        }
        arr[index] = val;
        ++size;
        return;
    }
    return insertVal(arr, size, val, index + 1);
}
void insertVal(int arr[], int size, int val){
    return insertVal(arr,size,val,0);
}
int findSubString(const string str, const string substr, int index){
    if(str.length() < 1){
        return - 1;
    }

    for(unsigned int i = 0; i< substr.length(); i++){
        if(str[index + i] != substr[i]){
            return findSubString(str, substr, index + 1);
        }
    }
    return index;
    
}

int findSubString(const string str, const string substr){
    return findSubString(str,substr,0);
}


void countFrequency(int arr[], int freq[], int size, int i, int j, int count){
    if(i == size){
        return;
    }
    if(j == size){
        freq[i] = count;
        countFrequency(arr,freq,size,i+1,0,0);
    }else{
        if(arr[i] == arr[j]){
            count++;

        }
        countFrequency(arr,freq,size,i,j+1,count);
    }
}
void countFrequency(int arr[],int freq[],int size){
    return countFrequency(arr, freq,size,0,0,0);
}

int main(){
    //Testing comparing strings
    cout << "Comparing ABC and D" << compareStrings("ABC"  , "D") << endl;
    cout << "Comparing ABC and ABC" << compareStrings("ABC" , "ABC") << endl;

    //Testing isPalindrome
    cout << "Testing if Racecar is palindrome or not " << endl;
    if(isPalindrome("racecar")){
        cout << "Yes, it is a palindrome" << endl;
    }else{
        cout << "NO, it is not a palindrome" << endl;
    }

    //Testing isAscending
    int arr[] = {1,3,5,7};
    cout<< "Testing isAscending" << endl;

    if(isAscending(arr,4)){
        cout << "Yes, it is ascending"<< endl;
    }else{
        cout << "No, it is not ascending" << endl;
    }

    //Testing insertVal
    int arr1[10] = {1,3,5,6};
    int size = 4;
    cout<< "Testing insertVal" << endl;
    insertVal(arr1, size, 4);
    cout << "After insering val 4: " << endl;
    for(int i = 0; i < size; i++){
        cout << arr1[i] << endl;
    }
    cout << endl;

    //Testing findSubString
    int index = findSubString("ABCBCBCA" , "CBC");
    cout << "Index: " << index << endl;

    int arr2[] = {2, 1, 4, 2, 6, 1, 3, 1, 2, 3, 7, 2, 6};
    int freq[13];
    countFrequency(arr2, freq, 13);
    cout << "Frequencies: ";
    for (int i = 0; i < 13; i++) {
        cout << freq[i] << " ";
    }
    cout << endl;

    return 0;
}
