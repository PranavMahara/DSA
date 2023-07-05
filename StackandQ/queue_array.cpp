#include<iostream>
using namespace std;

#define MAX 10

class queue{
    int a[MAX];
    int r,f;
    public:
        void init(){
            r=-1;
            f=-1;
        }

        void enqueue(int d){
            if(r==MAX-1){
                cout<<"queue is full "<<endl;
            }
            else{       // have to put it in else // youll only see the mistake when overflown
                r++;
                a[r]=d;
            }
        }

        int dequeue(){
            if (r==f){
                cout<<"queue is empty"<<endl;
                return 999;
            }
            f++;
            return a[f];
        }

        void display(){
            for(int i=f+1; i<=r; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }

        bool isempty(){
            if (r==f){
                return true;
            }
            return false;
        }
};

int main(){
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int d,x,choice;
    queue q;
    q.init();
    do{
        cout<<"Enter choice 1=enqueue, 2=dequeue, 3=display queue : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to be enqueued : ";
                cin>>d;
                q.enqueue(d);
                break;
            case 2:
                x=q.dequeue();
                if(x!=999){
                    cout<<"dequeued element : "<<x<<endl;
                }
                break;
            case 3:
                cout<<"queue is : ";
                q.display();
                break;
                
        }
    }
        while (choice>=1 && choice<=3);
    return 0;
}

