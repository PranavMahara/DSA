#include<iostream>
using namespace std;

class node{
    int name;
    int num;
    node *suc;
    node *pre;

    public:

        node *head=NULL;

        void insert_newstudent(string n,string s){
            node * temp=new node();
            temp->name=n;
            temp->num=s;
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

        void del_duplicate(){
            if (head==NULL){
                cout<<"list is empty cant delete"<<endl;
            }
            else{
                node *cur=head;
                node *trav=cur->suc;
                node *temp;
                while (trav!=cur){
                    if (trav->num==cur->num){
                        cout<<trav->name<<" has been deleted, cuase it has state : "<<trav->num<<endl;
                        (trav->suc)->pre=trav->pre;
                        (trav->pre)->suc=trav->suc;
                        temp=trav;
                        delete (trav);
                        trav=temp->suc;
                    }
                    else{
                        cout<<trav->name<<endl;
                        trav=trav->suc;
                    }
                }
            }
        }

        void display(){
            node *temp=head;
            while (temp->suc!=head){
                cout<<temp->name<<" "<<temp->num<<",   ";
                temp=temp->suc;
            }
            cout<<temp->name<<" "<<temp->num<<endl;
        }
};

int main(){
    node n;
    n.insert_newstudent("1","a");
    n.insert_newstudent("2","b");
    n.insert_newstudent("3","c");
    n.insert_newstudent("5","a");
    n.display();
    n.insert_newstudent("4","d");
    n.display();
    n.insert_newstudent("5","a");
    n.display();
    n.del_duplicate();
    n.display();
    return 0;
}