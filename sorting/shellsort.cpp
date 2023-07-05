#include <iostream>
using namespace std;

int main(){         // TC = nlogn for best, and n^2 for worst, if used Knewth sequence max = n^3/2
    int n, j, k, temp;
    cout << "Enter total number of elements : ";
    cin >> n;

    int a[n];
    cout << "Enter the elements of the array : ";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    int dist = n / 2;

    for (int i = dist; i > 0; i = i / 2){
        if (i % 2 == 0){        // dist always = odd
            i++;
        }

        for (j = i; j < n; j++){        // j = to get the forward ele of pair of ele to be swapped
            for (k = j - i; k >= 0; k = k - i){     // k = to get recursive backward ele in all case cause
                if (a[k + i] < a[k]){               // compare only a[k] and a[j]
                    temp = a[k + i];
                    a[k + i] = a[k];
                    a[k] = temp;
                }

                else{
                    break;
                }
            }
        }
    }

    cout<<"Sorted Array : ";
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}