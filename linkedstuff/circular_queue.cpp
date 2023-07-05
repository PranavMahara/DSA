#include<iostream>
using namespace std;

class node{
    public:
        int Size, f, r;         // definign everything in public cause ur init it in int main
        int *arr;

        int isEmpty(){
            if(r==f){
                return 1;
            }
            return 0;
        }

        int isFull(){
            if((r+1)%Size == f){
                return 1;
            }
            return 0;
        }

        void enqueue( int val){
            if(isFull()){
                cout<<"Queue is full"<<endl;
            }
            else{
                r = (r +1)%Size;        // this is basiclally r=r+1, only not when r>size
                arr[r] = val; 
                cout<<"Enqueue Element --> "<<val<<endl;
            }
        }

        int dequeue(){
            int a = -1;
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
            }
            else{
                f = (f +1)%Size;
                a = arr[f]; 
            }
            return a;
        }
};

int main(){
    node cq;
    cq.Size = 4;
    cq.f = cq.r = 0;

    cq.arr = new int[cq.Size];      // very imp to define basically int arr[5] down here
                                    // its basiaclly node *temo = new node();
    cq.enqueue(12);
    cq.enqueue(15);
    //cq.enqueue(1); 
    cout<<"Dequeing element : "<<cq.dequeue()<<endl;
    cout<<"Dequeing element : "<<cq.dequeue()<<endl;
    cout<<"Dequeing element : "<<cq.dequeue()<<endl;
    cq.enqueue(41); 

    if(cq.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }

    if(cq.isFull()){
        cout<<"Queue is full"<<endl;
    }

    return 0;
}

/*
#include<iostream>
using namespace std;

#define Size 5

class node{
    public:
        int  f=0, r=0;         // definign everything in public cause ur init it in int main
        int arr[Size];

        int isEmpty(){
            if(r==f){
                return 1;
            }
            return 0;
        }

        int isFull(){
            if((r+1)%Size == f){
                return 1;
            }
            return 0;
        }

        void enqueue( int val){
            if(isFull()){
                cout<<"Queue is full"<<endl;
            }
            else{
                r = (r +1)%Size;        // this is basiclally r=r+1, only not when r>size
                arr[r] = val; 
                cout<<"Enqueue Element --> "<<val<<endl;
            }
        }

        int dequeue(){
            int a = -1;
            if(isEmpty()){
                cout<<"Queue is empty"<<endl;
            }
            else{
                f = (f +1)%Size;
                a = arr[f]; 
            }
            return a;
        }
};

int main(){
    node cq;
    
    cq.enqueue(12);
    cq.enqueue(15);
    //cq.enqueue(1); 
    cout<<"Dequeing element : "<<cq.dequeue()<<endl;
    cout<<"Dequeing element : "<<cq.dequeue()<<endl;
    cout<<"Dequeing element : "<<cq.dequeue()<<endl;
    cq.enqueue(41); 

    if(cq.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }

    if(cq.isFull()){
        cout<<"Queue is full"<<endl;
    }

    return 0;
}
*/