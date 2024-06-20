int jumpSearch(int arr[], int x, int n) {
    // TODO: print the traversed indexes and return the index of value x in array if x is found, otherwise, return -1.
    int i = 0;
    int jump = sqrt(n);
    while(i < n){
        cout << i << " ";
        if(arr[i] > x) break;
        else if(arr[i] == x) return i;
        i += jump;
    }
    for(int j = i - jump + 1; j < i; j ++){
        cout << j << " ";
        if(arr[j] ==x) return j ;
    }
    return -1;
    
}