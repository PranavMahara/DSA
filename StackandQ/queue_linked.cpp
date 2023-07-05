#include<iostream>
using namespace std;

class node{
    int num;
    node *next;
    public:

        node *f=NULL;
        node *r=NULL;
    
        void enqueue(int d){
            node *current= new node();
            current->num=d;
            current->next=NULL;
        if(r==NULL){
            r=current;
            f=current;
        }
        else{               // dont simply write it without else (there is code above if also)
            r->next=current;
            r=current;
        }
        }

        int dequeue(){
            //if(r==NULL){
            //    cout<<"Queue is empty."<<endl;      // this doesnt execute cause r never is null actually
            //    return 999;
            //}1
            if (f==NULL){
                cout<<"Queue is empty"<<endl;
                return 999;
            }
            node *temp=f;     // point is to save memory cause once we shif the pointer the deleted node
            int x=f->num;     // still exists hence we use this temp to delete it 
            f=f->next;
            delete(temp);       // this doesnt del pointer temp it deletes obj/node stored in pointer
            return x;
        }

        void display(){
            node *temp=f;
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
    node q;
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
                    cout<<"dequeue element : "<<x<<endl;
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

