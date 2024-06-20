int binarySearch(int arr[], int left, int right, int x)
{
    
    if(left <= right){
        int mid = (left + right) / 2;
        cout << "We traverse on index: " << mid << endl;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) return binarySearch(arr, mid + 1, right, x);
        else return binarySearch(arr, left, mid - 1, x);
    }
    return -1;
}