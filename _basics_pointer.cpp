//concept of pointers 
// & = add of operator
// * = value at 

#include<iostream>
using namespace std;

int main(){
    int a=10;
    int *abc = &a;

    int arr[5];
    arr[0]=1;
    arr[1]=2;
    arr[2]=3;

    int *def = arr;     // pointer def points at first ele of array
    int *x = &arr[0];   // both are equivalent

    x++;

    cout<<*def<<endl;
    cout<<*x<<endl;   
    return 0;
}