#include<iostream>
using namespace std;

class node{
    int num;
    node *next;
    node *head=NULL;
    node *temp=NULL;
    node *trav=NULL;
    public:

        void insert(){
                node *cur=new node();
                cout<<"enter a number :";
                int d;
                cin>>d;
                cur->num=d;
                cur->next=NULL;
                if (head==NULL){
                    head=cur;
                }
                else{
                    node *temp2=head; 
                    while (temp2->next!=NULL){
                        temp2=temp2->next;
                    }
                    temp2->next=cur;
                }
        }

        void sort(){
            temp=head;
            while(head!=NULL){
                trav=temp->next;
                node *min=temp;
                while(trav!=NULL){
                    if(trav->num < min->num){
                        min->num = trav->num;
                    }
                    trav=trav->next;
                }
                int tem=temp->num;
                temp->num=min->num;
                min->num=tem;

                temp=temp->next;
            }
        }

        void display(){
            node *temp2=head;
            while (temp2!=NULL){
                cout<<temp2->num<<" ";
                temp2=temp2->next;
            }
            cout<<endl;
        }
};

int main(){
    node n;
    cout<<"enter number of entries in unsorted array : ";
    int x;
    cin>>x;
    for (int i=0; i<x; i++){
        n.insert();
    }
    n.display();
    n.sort();
    n.display();
    return 0;
}