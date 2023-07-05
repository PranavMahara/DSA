#include<iostream>
using namespace std;

class node{
    int num;
    node *next;
    
    public:
        node *first;

        void init(){
            first=NULL;
        }

        void f_insert(int d){
            node *current=new node();
            current->num=d;
            current->next=NULL;
            if (first==NULL){
                first=current;
            }
            else{
                current->next=first;
                first=current;
            }
        }

        int f_delete(){
            if (first==NULL){
                cout<<"Empty list cant delete."<<endl;
                return 999;
            }
            node *temp=first;
            int x=first->num;
            first=first->next;
            delete(temp);
            return x;
            cout<<"Deleted item is : "<<x<<endl;
        }

        void b_insert(int d){
            node *current=new node();
            current->num=d;
            current->next=NULL;
            if (first==NULL){
                first=current;
            }
            else{
                node *temp=first;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=current;
            }
        }

        int b_delete(){
            node *temp=first;   // temp is used for basic del of node
            node *prev=NULL;    // prev is req to change the next of the new last node to NULL
            while(temp->next!=NULL){
                prev=temp;
                temp=temp->next;
            }                       // in the last loop temp will have last node and prev 2nd last
            int x=temp->num;
            delete(temp);
            prev->next=NULL;
            return x;
        }

        void m_insert(int d,int n){
            node *current=new node();   // current is used for basic creation of new node
            current->num=d;
            current->next=NULL;
            node *temp=first;   // require this for reaching mid without touching first
            int i=1;
            while(i<n){     // not equal to, only lesser than
                temp=temp->next;    // temp will be the node after which you have to insert
                i++;
            }
            current->next=temp->next;   
            temp->next=current;
        }

        int m_delete(int x){
            node *temp=first, *prev=NULL;       /// again here pre is req
            while(temp->num!=x && temp!=NULL){
                prev=temp;
                temp=temp->next;
            }
            if (temp==first){
                cout<<"Element doesnt exist in linked list."<<endl;
            }
            prev->next=temp->next;             /// to perform this 
            delete (temp);
            return x;
        }

        void display(){
            node *temp=first;
            while (temp!=NULL){
                cout<<temp->num<<" ";
                temp=temp->next;
            }
            cout<<endl;
        }

};

int main()
{
    int choice, val;
    node obj;
    obj.init();
    do
    {
        cout<<"1. Insertion At Begin"<<endl;
        cout<<"2. Insertion At End"<<endl;
        cout<<"3. Delete at Front"<<endl;
        cout<<"4. Delete At End"<<endl;
        cout<<"5. Insert in the Middle"<<endl;
        cout<<"6. Delete any Value"<<endl;
        cout<<"7. Display"<<endl;
        cout << "Enter choice ---> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value : ";
            cin >> val;
            obj.f_insert(val);
            break;
        case 2:
            cout << "Enter the value : ";
            cin >> val;
            obj.b_insert(val);
            break;
        case 3:
            obj.f_delete();
            break;

        case 4:
            obj.b_delete();
            break;
        case 5:
            cout<<"Enter the value : ";
            cin>>val;

            int index;
            cout<<"Enter after which index value to enter : ";
            cin>>index;

            obj.m_insert(val, index);
            break;

        case 6:
            cout<<"Enter the value : ";
            cin>>val;
            obj.m_delete(val);
            break;

        case 7:
            obj.display();
            break;
        }
    } while (choice>=1 && choice<=7);
}