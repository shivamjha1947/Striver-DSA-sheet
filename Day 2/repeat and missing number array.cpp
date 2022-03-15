int *findTwoElement(int *arr, int size) {
    // code here
    static int a[2];
    int i;
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            a[0]=abs(arr[i]);
    }

    for (i = 0; i < size; i++) {
        if (arr[i] > 0)
            a[1]=(i + 1);
    }
    return a;
}
