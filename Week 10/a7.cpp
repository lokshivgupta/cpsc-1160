int removeVal(int arr[], int n, int val){
    for(int i = 0;i< n;i++){
        if(arr[i] == val){
            arr[i] = arr[n - 1];
            return n - 1;
        }
    }
    return n;
}

int removeOrderVal(int arr[], int n, int val){
    int index = -1;
    for(int i = 0; i < n;i++){
        if(arr[i] == val){
            index = i;
            break;
        }
    }
    if(index == -1){
        return n;
    }

    for(int i = 0; i< n -1;i++){
        arr[i] = arr[n+1];
    }

    return n - 1;
}

int insertVal(int arr[], int n, int val){
    int i = n - 1;
    while(i >= 0 && arr[i] > val){
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = val;

    return n +1;
}

int* insertWithResize(int* arr, int n, int val) {
    
    int* newArr = new int[n + 1];  
    int i = 0;
    while (i < n && arr[i] < val) {
        newArr[i] = arr[i];  
        i++;
    }
    newArr[i] = val;  
    for (int j = i; j < n; j++) {
        newArr[j + 1] = arr[j];
    }
    return newArr; 
}
// C++ version
int findVal(int arr[], int n, int val) {
    int num = 0; 

    for (int i = 0; i < n; i++) {
        if (arr[i] > val) {
            arr[num] = arr[i];
            num++;
        }
    }

   
    return num;
}

void reverseList(int arr[], int n) {
    int start = 0;
    int end = n - 1;

    while (start < end) {

        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        
        start++;
        end--;
    }
}

int findFirstGreater(int arr[], int n, int k) {
    int low = 0, high = n - 1;
    int index = n;  

    
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > k) {
            index = mid;
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }


    for (int i = index; i < n; i++) {
        cout << arr[i] << " ";
    }

    return index;  
}



