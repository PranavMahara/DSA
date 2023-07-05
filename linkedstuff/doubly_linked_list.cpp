#include<iostream>
using namespace std;

class node{
    int num;
    node *suc;
    node *pre;

    public:

        node *head=NULL;

        void insert_beg(int d){
            node * temp=new node();
            temp->num=d;
            temp->suc=NULL;
            temp->pre=NULL;
            if (head==NULL){
                head=temp;
            }
            else{
                temp->suc=head;
                head->pre=temp;
                head=temp;
            }
        }

        void delete_beg(){
            if (head==NULL){
                cout<<"list is empty cant delete"<<endl;
            }
            else{
                node *temp=head;
            cout<<temp->num<<" has been deleted"<<endl;
            (head->suc)->pre=NULL;
            head=head->suc;
            delete (temp);
            }
        }

        void insert_mid(int d, int n){
            node *temp=new node();
            temp->num=d;
            temp->suc=NULL;
            temp->pre=NULL;

            node *move=head;
            int i =1;
            while(i<n){
                if(move->suc==NULL){
                    break;
                }
                move=move->suc;
                i++;            // in the last iteration move will be at he node after which u wanna insert
            }
            if (move->suc==NULL){
                temp->pre=move;
                temp->suc=NULL;
                move->suc=temp;
            }
            else if (n<1){
                temp->pre=NULL;
                temp->suc=move;
                move->pre=temp;
                head=temp;
            }
            else{
                temp->pre=move;
                temp->suc=move->suc;
                move->suc=temp;
                (move->suc)->pre=temp;
            }
        }

        int delete_mid(int val){
            node *temp=head;
            while(temp->num!=val){     // loop terminates when temp points at the node that is 
                temp=temp->suc;         // needed to be deleted
            }
            (temp->pre)->suc=temp->suc;
            (temp->suc)->pre=temp->pre;
            delete(temp);
            return val;
        }

       void b_insert(int d){
            node *current=new node();
            current->num=d;
            current->suc=NULL;
            current->pre=NULL;

            if (head==NULL){
                head=current;
            }
            else{
                node *temp=head;
                while (temp->suc!=NULL){
                    temp=temp->suc;
                }
                temp->suc=current;
                current->pre=temp;
            };
        }

        int b_delete(){
            node *temp=head;
            while (temp->suc!=NULL){
                temp=temp->suc;
            }
            int x=temp->num;
            (temp->pre)->suc=NULL;
            cout<<x<<" has been deleted."<<endl;
            delete(temp);
            return x;
        }

        void display(){
            node *temp=head;
            while (temp->suc!=NULL){
                cout<<temp->num<<" ";
                temp=temp->suc;
            }
            cout<<temp->num<<endl;
        }
};

int main()
{
    int choice, val;
    int str;
    node obj;
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
            obj.insert_beg(val);
            break;

        case 2:
            cout << "Enter the value : ";
            cin >> val;
            obj.b_insert(val);
            break;

        case 3:
            obj.delete_beg();
            break;

        case 4:
            obj.b_delete();
            break;

        case 5:
            cout<<"Enter the value : ";
            cin>>val;

            int index;
            cout<<"Enter the index value : ";
            cin>>index;

            obj.insert_mid(val, index);
            break;

        case 6:
            cout<<"Enter the value : ";
            cin>>val;
            obj.delete_mid(val);
            break;

        case 7:
            obj.display();
            break;
        }
    } while (choice>=1 && choice<=7);
}