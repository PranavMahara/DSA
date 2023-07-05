#include <iostream>
using namespace std;

int main(){
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int n;
    string s,x;
    cout<<"how many names : ";
    cin>>n;
    string a[n];
    cout<<"enter these names : "<<endl;
    for (int i=0; i<n; i++){
        cin>>s;
        a[i]=s;
    }
    cout<<"name to be searched : ";
    cin>>x;
    int l,mid,h;
    l=0;
    h=n-1;
    while(l<=h){
        mid=(l+h)/2;
        if (x==a[mid]){
            cout<<"name found "<<endl;
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
        cout<<"name not found";
    }
}