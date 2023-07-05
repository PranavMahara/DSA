// same as singly linked list just link the last node with the first

#include<iostream>
using namespace std;

class node{
    public:
        int num;
        node *next;
        node *head = NULL;

        void display(){
            node *temp = head;
            if(head == NULL){
                cout<<"The list is empty"<<endl;
            }

            while(temp->next!=head){    // head cause we go all the way round and come back to first element
                cout<<temp->num<<" ";
                temp = temp->next;
            }
            cout<<temp->num<<" ";
            cout<<endl;
        }

        void beg_insert(int d){
            node *temp = new node();
            temp->next = temp;      // VERY IMP cause were making a circular list it has to point to itself
            temp->num = d;
            if(head == NULL){
                head = temp;
            }

            else{
                node *traverse = head;      // to traverse when more than one ele is there in ciruclar list
                temp->next = head;      // to connect new first ele to old first

                while(traverse->next!=head){        // used to insert properly
                    traverse = traverse->next;      // cause without actually going all the way round you cant 
                }                                   // inset as the last node will not be able to get add of first

                traverse->next = temp;  //connecting last to new first
                head = temp;            // changing head to new first
            }
        }  

        void end_insert(int data){
            node *temp = new node();
            temp->next = temp;      // VERY IMP cause were making a circular list it has to point to itself
            temp->num = data;
            if(head == NULL){
                head = temp;
            }

            else{                           // exact same code as beg_insert only one diff ie -> head not changed
                node *traverse = head;
                while(traverse->next != head){
                    traverse = traverse->next;
                }

                traverse->next = temp;      
                temp->next = head;          // only difference is no change in head cause here its END insert
            }
        }  

        void end_delete(){

            if(head==NULL){
                cout<<"The list is empty"<<endl;
            }

            if(head->next == head){
                cout<<"The deleted element is "<<head->num<<endl;
                head = NULL;
            }

            else{
                node *trav1 = head;
                node *trav2 = head->next;       // two pointer needed
                                                // cause one will be used to free del ele and other for 
                while(trav2->next!=head){       // changing 2nd last ele to last ele
                    trav1 = trav1->next;
                    trav2 = trav2->next;
                }

                trav1->next = head;
                cout<<"Deleted element --> "<<trav2->num<<endl;
                delete(trav2);
            }
        }

        void front_delete(){
            if(head==NULL){
                cout<<"the list is empty"<<endl;
            }

            else if(head->next ==head){
                cout<<"The deleted node is "<<head->num<<endl;
                head = NULL;
            }

            else{
                node *temp, *trav;      //temp is used to hold head only
                trav = head;
                while(trav->next!=head){        // in front_del we stored 2nd last and last in pointers
                    trav = trav->next;          // in end_del we store last and old first in pointers
                }
                temp = head;
                head = head->next;
                cout<<"The deleted node is "<<temp->num<<endl;
                delete(temp);
                trav->next = head;      // connect lat ele to new first ele
            }
        }
};

int main(){
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int choice, x;
    node obj;

    cout<<"1-Insert in the front "<<endl;
    cout<<"2-Insert at the back"<<endl;
    cout<<"3-Delete from the front"<<endl;
    cout<<"4-Delete from back"<<endl;
    cout<<"5-Display"<<endl;
    cout<<"6-Exit"<<endl;
    do{
        cout<<"Enter choice ---> ";
        cin>>choice;

        switch (choice){
        case 1:
            cout<<"Enter the element : ";
            cin>>x;
            obj.beg_insert(x);
            break;

        case 2:
            cout<<"Enter the element : ";
            cin>>x;
            obj.end_insert(x);
            break;
        case 3:
            obj.front_delete();
            break;

        case 4:
            obj.end_delete();
            break;

        case 5:
            obj.display();
            break;
        }

    } while (choice !=6);
    return 0;
}