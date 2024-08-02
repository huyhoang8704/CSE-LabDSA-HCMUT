string minDiffPairs(int* arr, int n) {
    string save = "";
    sort(arr, arr + n);
    int min = INT8_MAX;
    for (int i = 0; i < n - 1; i++) {
        int g = *(arr+i) ;
        int k = *(arr + i + 1);
        int a = abs(g-k);
        if (min > a) {
            min = a;
        }
    }
    for (int i = 0; i < n - 1; i++) {
        int a = abs(*(arr + i) - *(arr + i + 1));
        if (a == min) {
            save = save + "(" + to_string(*(arr + i)) + ", " + to_string(*(arr + i + 1)) + "), ";
        }
    }
    if (save.length() > 1) {
        save = save.substr(0, save.length() - 2);
    }
    return save;
}