void insertionSort(int list[], int size){
    for(int i = 1; i < size; i++){
        //Insert list[i] into the sorted ist on it's left
        int toInsert = list[i];
        int j = i - 1
        for( ;j>= 0 && list[j] > toInsert; j--){
            list[j+1] = list[j];

        }
        list[j+1] = toInsert;
    }
}