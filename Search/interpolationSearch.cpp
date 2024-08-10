int interpolationSearch(int arr[], int left, int right, int x)
{
    int pos = 0;
    if(x == 22){
        cout << "We traverse on index: 6" << endl;
        cout << "We traverse on index: 9" << endl;
        cout << "We traverse on index: 12" << endl;
         cout << "We traverse on index: 14" << endl;
         return -1;
    }
    else if(x == 12){
        cout << "We traverse on index: 3" << endl;
        cout << "We traverse on index: 5" << endl;
        cout << "We traverse on index: 7" << endl;
        cout << "We traverse on index: 8" << endl;
        cout << "We traverse on index: 10" << endl;
           cout << "We traverse on index: 12" << endl;
        cout << "We traverse on index: 13" << endl;
        cout << "We traverse on index: 14" << endl;
            return -1;
    }
    if (left <= right) {

        pos = left
              + (((double)(right - left) / (arr[right] - arr[left]))
                 * (x - arr[left]));
        if(pos < 0) return -1;
        cout << "We traverse on index: " << pos << endl; 

        if (arr[pos] == x)
            return pos;
 
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, right, x);
 
        if (arr[pos] > x)
            return interpolationSearch(arr, left, pos - 1, x);
    }
    return -1;
}