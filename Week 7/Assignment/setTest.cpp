#include "set.h"
#include "set.cpp"
#include<ctime>
#include<cstdlib>
using namespace std;


template<typename T>
T* extractArray(const set<T>& t1);


int main(){
    set<int> randIntSet;
    srand(time(0));
    while(randIntSet.getSize() < 20){
        int random = rand() % 100 + 1;
        randIntSet.add(random);
    }
    set<int>* randIntCopy = new set<int>(randIntSet);
    int added = 0;


    while(added< 5){
        int random = rand() % 100 + 1;

        if(randIntCopy->add(random)){
            added++;
        }
    }

    randIntSet.displaySet();
    randIntCopy->displaySet();

    set<int> intersectedSet = randIntSet.intersection(*randIntCopy);
    cout<<"Intersection of Sets: " <<endl;
    intersectedSet.displaySet();

    set<int> unions = randIntSet.unionSet(*randIntCopy);
    cout<<"Union of the sets: "<<endl;
    unions.displaySet();

    set<int> symmetricalSet = randIntSet.symmetry(*randIntCopy);
    cout<<"Symmetrical Set: " << endl;
    symmetricalSet.displaySet();

    bool equality = randIntCopy->isEqual(randIntSet);
    if(equality){
        cout << "The sets are equal" <<endl;
    }else{
        cout << "The sets are not equal" << endl;
    }

    for(unsigned int i = 0; i < 3; i++){
        int min;
        if(randIntCopy->removeMin(min)){
            cout << "Minimun values are: " << min<<endl;
        }
    }
    for(unsigned int i = 0; i < 2; i++){
        int max;
        if(randIntCopy->removeMax(max)){
            cout<< "Maximum values are: " << max << endl;
        }
    }

    int* extractedData = extractArray(randIntSet);
    unsigned int sze = randIntSet.getSize();
    cout <<"Extracted Array: " << endl;
    cout << "{";
    for(unsigned int i = 0; i < sze;i++){
        
        cout<< extractedData[i];
        if(i != sze-1){
            cout << ",";
        }
    }
    cout << "}";
    cout <<endl;
    delete [] extractedData;

    delete  randIntCopy;
    return 0;
}

template<typename U>
U* extractArray(const set<U>& t1){
    U* data;
    unsigned int size = t1.getSize();
    unsigned int cap = size + 10;
    data = new U[cap];
    for(unsigned int i = 0; i < size; i++){
      
        data[i] = t1.data[i];
    }
    
    return data;
}