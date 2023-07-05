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
    int l,mid,h;
    l=0;
    h=n-1;
    while(l<=h){
        mid=(l+h)/2;
        if (x==a[mid]){
            cout<<"number found at "<<mid<<"th index in list"<<endl;
            break;
        }
        else if(x<a[mid]){
            h=mid-1;
        }
        else if(x>a[mid]){
            l=mid+1;
        }
    }
    if (x!=a[mid]){
        cout<<"number not found";
    }
}