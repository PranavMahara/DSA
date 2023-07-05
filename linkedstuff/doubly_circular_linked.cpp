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
            temp->suc=temp;
            temp->pre=temp;
            if (head==NULL){
                head=temp;
            }
            else{
                temp->suc=head;
                temp->pre=head->pre;
                (head->pre)->suc=temp;
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
            (head->suc)->pre=head->pre;
            (head->pre)->suc=head->suc;
            head=head->suc;
            delete (temp);
            }
        }

        void insert_mid(int d, int n){
            node *temp=new node();
            temp->num=d;
            temp->suc=temp;
            temp->pre=temp;

            if (head==NULL){
                head=temp;
            }
            
            node *move=head;
            int i =1;
            while(i<n){
                move=move->suc;
                i++;            // in the last iteration move will be at he node after which u wanna insert
            }
            if (n==0){
                insert_beg(d);
            }   
            else if (n==1){
                (head->suc)->pre=temp;
                temp->suc=(head->suc);
                temp->pre=head;
                head->suc=temp;
            }
            else{
                (move->suc)->pre=temp;
                temp->suc=(move->suc);
                temp->pre=move;
                move->suc=temp;
            }
        };

        int delete_mid(int val){
            node *temp=head;
            while(temp->num!=val){      // loop terminates when temp points at the node that is 
                temp=temp->suc;         // needed to be deleted
            }
            if (head==temp){
                (temp->pre)->suc=temp->suc;
                (temp->suc)->pre=temp->pre;
                cout<<temp->num<<" is deleted."<<endl;
                head=head->suc;
                return 0;
            }
            else{
                cout<<temp->num<<" is deleted."<<endl;
                (temp->pre)->suc=temp->suc;
                (temp->suc)->pre=temp->pre;
                delete(temp);
                return 0;
            }
        };

       void b_insert(int d){
            node *current=new node();
            current->num=d;
            current->suc=current;
            current->pre=current;

            if (head==NULL){
                head=current;
            }
            else{
                current->suc=head;
                current->pre=head->pre;
                (head->pre)->suc=current;
                head->pre=current;
            };
        }

        int b_delete(){
            node *temp=head->pre;
            int x=temp->num;
            head->pre=temp->pre;
            (temp->pre)->suc=head;
            delete(temp);
            cout<<x<<" has been deleted."<<endl;
            return x;
        }


        void display(){
            node *temp=head;
            while (temp->suc!=head){
                cout<<temp->num<<" ";
                temp=temp->suc;
            }
            cout<<temp->num<<" "<<endl;
        }
};

int main()
{
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int choice, val;
    node obj;
    cout<<"1. Insertion At Begin"<<endl;
    cout<<"2. Insertion At End"<<endl;
    cout<<"3. Delete at Front"<<endl;
    cout<<"4. Delete At End"<<endl;
    cout<<"5. Insert in the Middle"<<endl;
    cout<<"6. Delete any Value"<<endl;
    cout<<"7. Display"<<endl;
    do
    {
        cout << "Enter choice ---> ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the value : ";
            cin >> val;
            obj.insert_beg(val);
            cout<<endl;
            break;

        case 2:
            cout << "Enter the value : ";
            cin >> val;
            obj.b_insert(val);
            cout<<endl;
            break;

        case 3:
            obj.delete_beg();
            cout<<endl;
            break;

        case 4:
            obj.b_delete();
            cout<<endl;
            break;

        case 5:
            cout<<"Enter the value : ";
            cin>>val;

            int index;
            cout<<"Enter the index value : ";
            cin>>index;

            obj.insert_mid(val, index);
            cout<<endl;
            break;

        case 6:
            cout<<"Enter the value : ";
            cin>>val;
            obj.delete_mid(val);
            cout<<endl;
            break;

        case 7:
            obj.display();
            cout<<endl;
            break;
        }
    } while (choice>=1 && choice<=7);
}