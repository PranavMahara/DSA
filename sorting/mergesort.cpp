#include <iostream>
using namespace std;

void merge(int a[], int l, int mid, int h)     // dont put [] and n in it
{
    int i = l;
    int j =mid+1;
    int k=l;
    int temp[50];
    while (i <= mid && j <= h)
    {
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= h)
    {
        temp[k] = a[j];
        k++;
        j++;
    }
    
    for(int i=l; i<k;i++){
        a[i]=temp[i];
    }
}

// dont put [] n in it
void msort(int a[], int l, int h)     // TC = nlogn from  T(n/2) = 2(T(n/2)) + O(n)
{
    if (l < h)      // to make sure it has 1 element in final step, ie there l=h (single ele arr) 
    {
        int mid = (l + h) / 2;
        msort(a, l, mid);       // (l --> mid ) cause that how we split the arrays left = l->mid 
        msort(a, mid + 1, h);           // right = mid+1 -- > h

        merge(a, l, mid, h);       // these 2 rec fxn break the arr down to 1 ele each 
                                    // then we perform merge from down to up
    }
}

int main()
{
    int n;
    cout << "Please enter the length of array : " << endl;
    cin >> n;

    int a[n];
    cout << "Please enter the elements : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    msort(a, 0, n - 1);     // dont put [] and n in it
    cout<<"The sorted array is : ";
    for (int i = 0; i < n; i++)
    {
        cout << a[i]<<" -> ";
    }
    return 0;
}

/*
void merge(int arr[], int l, int h, int mid){
    int i = l;      // i = var for left arr
    int j = mid+1;  // j = right sub array
    int k = l;      // k = for resultant array

    int temp[50];       // to temp store ele in an arr using k var

    while(i<=mid && j<=h){      // to make sure both subarrays have elements (even 1 satisfies )
        if(arr[i]<arr[j]){
            temp[k]=arr[i];     // if ith < jth copy ith to res arr
            i++;                //  move to next index in left and res arr
            k++;
        }

        else{
            temp[k]=arr[j];     // if ith > th copy jth to res arr
            k++;
            j++;                //  move to next index in left and res arr
        }
    }
                            // after this loop terminates one of the two arrays is empty

    while(i<=mid){
        temp[k++] = arr[i++];
    }

    while(j<=h){
        temp[k++] = arr[j++];
    }

    for(i = l; i<k; i++){           // copying (overwriting) ele in og array from temp arr
        arr[i]=temp[i];
    }
}
*/