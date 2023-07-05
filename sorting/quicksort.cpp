#include<iostream>
using namespace std;

void quick(int a[50], int left, int right){     // TC = nlogn for best, and n^2 for worst
    if(left>=right)         // to check if arr cont single ele, for single ele arr l=r
        return;

    int pivot = left;       // assigning pivot to first ele in arr for our code
    int l = left;           // l = first of sub arra
    int r = right;          // r = last of sub arr

    while(l<r){             // cond after which we swap pivot with "r" not "right"
        while(a[r]>a[pivot]){
            r--;            // a[r]>a[p] not req go backwards
        }
        while(a[l]<a[pivot]){
            l++;            // a[l]<a[p] not req go forwards
        }

        if (l<r){
            int temp = a[l];        // to swap when l<r only
            a[l] = a[r];
            a[r] = temp;
        }
    }

    int temp = a[r];            //  swap pivot with "r" not "right"
    a[r] = a[pivot];
    a[pivot] = temp;            // r and pivot got swapped
    
                                // left and right have not been touched all this time 
    quick(a, left, r-1 );       // the lhs of arr, form left -> r-1 (the ele before where pivot was)

    quick(a, r+1, right);       // the rhs of arr, form r-1 -> right (the ele after where pivot was)
}

int main(){
    int n, a[50];
    cout<<"How many numbers do you want to input : ";
    cin>>n;
    cout<<"Enter the "<<n<<" elements : "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i];
     }
    cout<<endl;

    quick(a, 0, n-1);
    
    cout<<"The sorted array is : ";
    for(int i=0; i<n; i++){
         cout<<a[i]<<" ";
     }

    return 0;
}