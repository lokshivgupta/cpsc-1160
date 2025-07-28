void sortingAlgorithm(int arr[], int size, bool ascending = true){
    int* sortArr = new int[size];

    for(int i = 0; i < size; i++){ 

       
        for(int j = 0; j < size; j++){  
            if(ascending){
                if(arr[i]> arr[j]){ 
                    count++; 
                }
                
            }else if(arr[i]<arr[j]){ 
                count++; 
            }
        }
        sortArr[count] = arr[i];  
    }

    for(int i = 0; i < size; i++){
        arr[i] = sortArr[i];  
    }

    delete[] sortArr;
}
