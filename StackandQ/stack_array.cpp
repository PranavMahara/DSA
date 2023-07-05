#include <iostream>
using namespace std;

# define MAX 10

class stack{
        int a[MAX];
        int top;
    public:
    
        void initialise(){
            top=-1;
        }

        void push(int x){
            if (top==MAX-1){
                cout<<"stack is overflown"<<endl;
            }
            else{
                top=top+1;
                a[top]=x;
                cout<<"pushed element is : "<<a[top]<<endl;
            }
        }

        int pop(){
            if(top==-1){
                cout<<"stack is underflown"<<endl;
            return 999;
            }
            int x= a[top];
            top=top-1;
            return x;
        }

        void display(){
            for (int i=0; i<=top; i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }

};

int main(){
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int d,x,choice;
    stack s;
    s.initialise();
    do{
        cout<<"Enter choice 1=push, 2=pop, 3=display stack : ";
        cin>>choice;
        switch(choice){
            case 1:
                cout<<"Enter element to be pushed : ";
                cin>>d;
                s.push(d);
                break;
            case 2:
                x=s.pop();
                if(x!=999){
                    cout<<"popped element : "<<x<<endl;
                }
                break;
            case 3:
                cout<<"stack is : ";
                s.display();
                break;
        
        }
    }
        while (choice>=1 && choice<=3);
    return 0;
}