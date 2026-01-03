#include<bits/stdc++.h>
using namespace std;
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}
int partition(vector<int>& arr, int low, int high) {
    int pivot=arr[low];
    int i=low,j=high;
    do{
        do{i++;}while(arr[i]<=pivot);
        do{j--;}while(arr[j]>pivot);
        if(i<j) swap(arr[i],arr[j]);
    }while(i<j);
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int>& arr, int low, int high) {
    if(low<high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex);
        quickSort(arr, pivotIndex + 1, high);
    }
}
int main() {
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int n = arr.size();
    quickSort(arr, 0, n);
    cout << "Sorted array: ";
    for (int val : arr) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
} 