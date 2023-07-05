#include<iostream>
using namespace std;

class node{
    int num;
    node *next;
    public:
        node *top=NULL;

        void push(int d){
            node *current=new node();
            
            current->num=d;
            current->next=NULL;
            if(top==NULL){
                top=current;
            }
            else{
                current->next=top;      // dont simply write without else cause itll run for the whole code 
                top=current;            // above it
            }
        }    

        int pop(){
            if(top==NULL){
                cout<<"stack underflown"<<endl;
                return 999;
            }
            int x=top->num;
            node *temp=top;     // this stored value of top in temp to help delete popped node
            top=top->next;
            delete(temp);    // deletes node in pointer temp to save space 
            return x;
        }

        void display(){
            node *temp=top;
            while (temp!=NULL){
                cout<<temp->num<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }
};

int main(){
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int d,x,choice;
    node s;
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