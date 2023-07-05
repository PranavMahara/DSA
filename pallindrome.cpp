// basic implementation of stack 

#include<iostream>
#include <string>        // to get all the functions rel to string datatype
using namespace std;

class node{
    int num;
    node *next;

    public:
        node *top=NULL;

        void push(char c){      // not string cause we'll be inputing only a single char at a time in stack
            node *current=new node();
            
            current->num=c;
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
    node stack;
    int input;
    cout<<"Enter a string to check for pallindrome : "<<endl;
    getline(cin,input);             // this is used to account for spaces also unlike normal cin
    
    int len;
    len=input.length();
    for (int i = 0; i < len; i++){
        stack.push(input[i]);
    }

    int output;
    for (int i = 0; i < len; i++){
        int x;           // has to be string snd not char even tho a is a char
        x=stack.pop();
        output.append(x);
    }

    if(input==output){
        cout<<"Entered string is a palindrome"<<endl;
        cout<<"As reverse : "<<output<<" and input :"<<input<<" are the same."<<endl;
    }

    else{
        cout<<"Not a palindrome"<<endl;
        cout<<"As reverse : "<<output<<" and input :"<<input<<" are not the same."<<endl;
    }

    return 0;
}