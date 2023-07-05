#include <iostream>
using namespace std;

void buildheap(int arr[], int n, int i){        // array, n and i (v)
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < n && arr[l] > arr[largest]){
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]){
        largest = r;
    }
    if (largest != i) {
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        buildheap(arr, n, largest);
    }
}

void sort(int arr[], int n){            // TC = nlogn , logn to build heap for an internal node
    for (int i = n / 2 - 1; i >= 0; i--){
        buildheap(arr, n, i);        // builds max heap for a certaing root node thne we swap it by going down
    }

    for (int i = n - 1; i > 0; i--) {       // to swap last=i and first =root = 0th ele, going from backwards
        swap(arr[0], arr[i]);
        buildheap(arr, i, 0);           // the buildheap for 0-n-1 ele exculding the just sorted one
    }
}

int main(){
    int n,arr[n];
    cout << "Enter total number of elements : ";
    cin >> n;
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr, n);       // only array and n

    cout<<"Sorted : ";
    for (int i = 0; i < n; i++){
        cout<<arr[i]<<" ";
    }    
    return 0;
}


/*
#include<iostream>
using namespace std;

int w;
int a[];
int n;

void buildheap(int v){          // for internal node v
    int w=2*v+1;                // left child = w
    while (w<n){                // checking if left child exists
        if (w+1<n){             // checking if right child exists
            if (a[w]<a[w+1]){
                w++;            // whichever is larger btw l and r take that w 
            }
            if (a[v]<a[w]){     // if parent < greatr leaf node, swap 
                int temp=a[v];
                a[v]=a[w];
                a[w]=temp;
            }
        }
    }
}

// for(int v=n/2 - 1; v>=0; v--)
//          buildheap(v)            // cause heap is built only for internal nodes
// if last ele = n= right child of last internal node, its parent v, where 2v + 2=n, so v=(n-2)/2 = n/2 -1 

// after an internal node swap have to check its child incase that is also an internal
// therefore do v=w; and then continue to build heap w=2v+1 ....

// at the end of a max heap, final step is swap largest ele ie root, with last ele and discard that as 
// that is sorted (max heap = increasing ie last ele = largest)

int main(){
    
    return 0;
}
*/