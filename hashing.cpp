#include <iostream>
using namespace std;

struct hash {
   int data;
   int key;
}

h[10];

int main(){
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int a[10]={28, 7, 26, 72, 51, 18, 23, 27, 29, 45};
    for(int i=0;i<10;i++)
    {
        h[i].key=(3*a[i]+2)%10;
        h[i].data=a[i];
    }

    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<10;j++)
        {
            if(h[i].key==h[j].key)
            {
                h[j].key=(h[j].key+1)%10;
            }
        }
    }
    cout<<"key data"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<h[i].key<<"   ";
        cout<<h[i].data<<endl;
    }

}