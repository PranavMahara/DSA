#include <iostream>
using namespace std;

void insertion(){           // TC = n^2 (worst) and best = n
    int i, temp, j, n;
    cout << "Enter the no of elements in the array : ";
    cin >> n;

    int a[n];
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // first ele is always sorted
    for (i = 1; i < n; i++){        // i is the first ele of unosorted arr = temp
        temp = a[i];
        j = i - 1;      // ele just beofore i 

        while (j >= 0 && a[j] > temp){      // j is last of sorted array 
            a[j + 1] = a[j];        // till  temp is smaller keep going back
            j = j - 1;
        }   // loop stops when j =at the pos where a smaller ele than temp exists       
        // when loop terminates there will be 2 copies of ele just larger than temp at j+1 and j+2  
        a[j + 1] = temp;        // replace the one on the left
    }

    cout<<"sorted array using insertion sort : ";
    for (i = 0; i < n; i++){
        cout << a[i] << " -> ";
    }
}

void selection(){           // TC = n^2 worst and best
    int a[50], i, j, n, temp;      // only step is to exchange min of unorted subarray with first ele of us arr

    cout << "Enter the no of elements in the array : ";
    cin >> n;
    cout << "Enter the elements of the array : ";
    for (i = 0; i < n; i++)
        cin >> a[i];

    // i is the first ele of unsorted array
    for (i = 0; i < n - 1; i++)     // n-1 cause n-1 iterations, cause if 1 ele if left in unsorted its sorted
    {
        int min = i;        // stores index of min ele not the ele itself
        for (j = i + 1; j < n; j++)     // used to find min in unsorted arr
        {
            if (a[j] < a[min])
                min = j;
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;          //swap min with first of us arr
    }

    cout<<"sorted array using selection sort : ";
    for (i = 0; i < n; i++){
        cout << a[i] << " -> ";
    }
}

int main()
{
    int choice;
    cout<<"1. Insertion Sort"<<endl;
    cout<<"2. Selection Sort"<<endl;
    cout<<"3. Exit"<<endl;

    do{
        cout<<"Enter choice : ";
        cin>>choice;
        switch (choice){
        case 1:
            insertion();
            cout<<endl;
            cout<<endl;
            break;
        
        case 2:
            selection();
            cout<<endl;
            cout<<endl;
            break;
        }
    } while (choice!=3);
    
    return 0;
}