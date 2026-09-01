#include<iostream>

using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int smallestIdx = i;
        for(int j =i+1; j<n; j++){
            if(arr[j]<arr[smallestIdx]){
                smallestIdx = j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

void printSort(int arr[], int n){
    for(int i =0; i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout << endl;
}

int main(){
    int n=5;
    int arr[] = {3,1,4,7,8};

    selectionSort(arr,n);
    printSort(arr,n);
    return 0;
}