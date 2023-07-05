#include <iostream>
using namespace std;

class node{
    string name;
    string state;
    node *suc;
    node *pre;

    public:

        node *head=NULL;

        void insert_newstudent(string n,string s){     // insert_newstudent
            node * temp=new node();
            temp->name=n;
            temp->state=s;
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

        void del_duplicate(){         // delete_forwards
            if (head==NULL){
                cout<<"list is empty cant delete"<<endl;
            }
            else{
                node *cur=head;
                while (cur->suc!=head){      // stop at (n-1)th ele as nth cant be a duplicate if pre (n-1) have been processed
                    cout<<"now current is "<<cur->name<<" with state : "<<cur->state<<endl;
                    node *trav=cur->suc;
                    node *temp;
                while (trav!=cur){
                    if (trav->state==cur->state){
                        cout<<trav->name<<" has been deleted, cause it has state : "<<trav->state<<endl;
                        (trav->suc)->pre=trav->pre;
                        (trav->pre)->suc=trav->suc;
                        temp=trav;
                        delete (trav);
                        trav=temp->suc;
                    }
                    else{
                        // cout<<"traverse is "<<trav->name<<endl;
                        trav=trav->suc;
                    }
                }
                cout<<cur->name<<" has been processed as current ."<<endl;
                cout<<endl;
                cur=cur->suc;
            }

        }
        }

        void display(){
            node *temp=head;
            while (temp->suc!=head){
                cout<<temp->name<<" "<<temp->state<<",   ";
                temp=temp->suc;
            }
            cout<<temp->name<<" "<<temp->state<<endl;
        }
};

// int main(){
//     node n;
//     n.insert_newstudent("1","a");
//     n.insert_newstudent("2","b");
//     n.insert_newstudent("3","c");
//     n.insert_newstudent("5","a");
//     n.display();
//     n.insert_newstudent("4","d");
//     n.display();
//     n.insert_newstudent("5","a");
//     n.display();
//     n.delete_forwards();
//     n.display();
//     return 0;
// }

int main() {
	node obj;
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
	obj.insert_newstudent("PPP", "Tamil Nadu");
	obj.insert_newstudent("QQQ", "Oman");
	obj.insert_newstudent("RRR", "Karnataka");
	obj.insert_newstudent("SSS", "Oman");
	obj.insert_newstudent("TTT", "Africa");
	obj.insert_newstudent("VVV", "Oman");
	obj.insert_newstudent("AAA", "Africa");
	obj.insert_newstudent("BBB", "Tamil Nadu");
	obj.insert_newstudent("CCC", "Oman");
	obj.insert_newstudent("DDD", "Karnataka");
	obj.insert_newstudent("EEE", "Oman");
	obj.insert_newstudent("FFF", "Africa");
    obj.display();
    cout<<endl;
    cout<<endl;
	obj.del_duplicate();
    cout<<endl;
    cout<<endl;
    cout<<"The final circular linked list is : "<<endl;
	obj.display();
    cout<<endl;

}