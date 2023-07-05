#include<iostream>
using namespace std;

void Towers(int n, int S, int A, int D){

// if datatype was char instead of string then while giving input in the last line u had to give it in 
// single inverted commas like Towers(n, 'A', 'B', 'C'); 

// using logic of visualisation to decide which tower comes when
// its SAD for input, then its SAD and ASD alternatively

    if(n>0){
        Towers(n-1, S, D, A);       // its the right rotate visualisation
        cout<<"Move a disc from "<<S<<" to "<<D<<endl;
        Towers(n-1, A, S, D);       // its the left rotate visualisation
    }
}

int main(){
    int n;
    cout<<"Enter the number of discs : ";
    cin>>n;

    Towers(n, "S", "A", "D");
    return 0;
}
