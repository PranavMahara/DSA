#include <iostream>
using namespace std;

int main(){
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int n,s,x;
    cout<<"How many numbers : ";
    cin>>n;
    int a[n];
    cout<<"Enter these numbers : ";
    for (int i=0; i<n; i++){
        cin>>s;
        a[i]=s;
    }
    cout<<"Numbers to be searched : ";
    cin>>x;
    for (int i=0; i<n; i++){
        if (a[i]==x){
            cout<<"\tNumber "<<x<<" is found in the list at "<<i<<"th index."<<endl;
            break;
        }
        else if (i==n-1)
            cout<<"\tNumber does not exit in the list."<<endl;
        else if(a[i]!=x)
            continue;
    }

}