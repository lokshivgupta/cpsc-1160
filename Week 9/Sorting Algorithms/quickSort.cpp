int partition(int list[], int startIndex, int endIndex);
void quickSort(int list[], int startIndex, int endIndex){
    if(endIndex > startIndex){
       int pivotIndex  = partition(list,startIndex,endIndex);
       quickSort(list,startIndex,pivotIndex-1);
       quickSort(list,pivotIndex+1,endIndex);
    }
}

int partition(int list[], int startIndex, int endIndex){

    int pivotValue = list[startIndex];
    int i = startIndex + 1;
    int j = endIndex;

    while(i <= j){
        while(i <= endIndex && list[i] < pivotValue){
            ++i;
        }
        while(j >= startIndex && list[j] >= pivotValue){
            --j;
            if(i < j){
                int temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }

        }
        
    }

    list[startIndex] = list[j];
    list[j] = pivotValue;

    return j;

}