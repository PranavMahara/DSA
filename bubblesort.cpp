#include<iostream>
using namespace std;

void printArray(int *A, int n){
    for(int i=0; i<n; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(int *A, int n){
    int temp;
    for (int i = 0; i < n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *A, int n){
    int temp, isSorted = 0;
    for (int i = 0; i < n-1; i++){
        cout<<"Working on pass "<<i+1<<endl;
        isSorted = 1;
        for(int j=0; j<n-i-1; j++){
            if(A[j]>A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                isSorted = 0;
            }
        }

        if(isSorted){
            return;
        }
    }
}

int main(){
    // int A[] = {1, 2, 5, 6, 12, 54, 625, 7, 23, 9, 987};
    int A[] = {1, 4, 2, 3};
    int n = 4;

    bubbleSortAdaptive(A, n);
    printArray(A, n);
    return 0;
}