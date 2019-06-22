#include <iostream>
using namespace std;

// insertion sort to sort an array
// Complexity: O(n^2)
void Insertion_Sort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Merge Sort
// Complexity: O(nlgn)
void Merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++){
        L[i] = arr[l + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2){
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void Merge_Sort(int arr[], int l, int r){
    if (l < r){
        int m = l + (r - 1)/2;
        Merge_Sort(arr, l ,m);
        Merge_Sort(arr, m+1, r);
        Merge(arr, l ,m, r);
    }
}


// Quick sort
void Quick_Sort(int arr[], int l, int h){
    int i = l;
    int j = h;
    int pivot = arr[(i + j) / 2];
    int temp;

    while (i <= j) {
        while(arr[i] < pivot){
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            i++;
            j--;
        }
    }
    if(j > l){
        Quick_Sort(arr, l, j);
    }
    if(i < h){
        Quick_Sort(arr, i, h);
    }
}


//Print function
void Print_Out(int arr[], int n){
    int i;
    for (i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


//Driver
int main() {
    int arr[] = {12, 11, 13, 5, 6, 2, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    Insertion_Sort(arr, n);
    Print_Out(arr, n);

    return 0;
}

