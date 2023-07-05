#include<iostream>
#include<string>            //to get all functionalities of string
using namespace std;


class stack{
    public:
        int top=-1, size=100;
        char *arr;         // will store add of only char
                           // in this code itll store add of first char of array created dynamically
        
        void push(char data){
            if(top == size-1){
                return;
            }

            top++;
            arr[top] = data;
        }

        char pop(){
            if(top==-1){
                return '\0';
            }
            
            char val = arr[top];
            top--;
            return val;
        }

        void display(){
            for(int i=0; i<=top; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }

        int priority(char data){ 
            if (data == '*' || data == '/' || data == '%'){     // this is correct
                return 4;                                       
            }

            else if (data == '-' || data == '+'){
                return 3;
            }

            else if (data == '>' || data == '<'){
                return 2;
            }

            else if (data == '^'){
                return 1;
            }

            else{
                return 0;
            }
        }
};

int main(){
    stack *s = new stack;
    s->arr = new char[s->size];
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    char opr;

    string inp, out;
    cout<<"Enter the input string : ";
    getline(cin, inp);                      // basically cin but takes spaces also as input

    for (int i = 0; i < inp.length(); i++){
        if((inp[i] == ' ') || (inp[i] == '\t')){
            continue;
        }

        else if((isdigit(inp[i])) || (isalpha(inp[i]))){
            out = out + inp[i];
            // cout<<out<<endl;
        }

        else if(inp[i] == '('){
            s->push(inp[i]);
            // s->display(s);
        }

        else if(inp[i] == ')'){
            do{
                opr = s->pop();
                if(opr == '('){
                    break;
                }
                //out = out + inp[i];   wrong char being added to ouput 
                out = out + opr;
            }while(opr != '(');
        }

        else{
            if(s->top == -1){
                s->push(inp[i]);
            }

            else{
                opr = s->pop();
                if(opr == '('){
                    s->push(opr);
                    s->push(inp[i]);
                }

                else{
                    while(s->priority(opr) >= s->priority(inp[i])){
                        //out = out + inp[i]; adding incorrect char onto output its opr not incoming
                        out = out + opr;
                        opr = s->pop();
                        if(opr == '\0'){
                            break;
                        }
                    }

                    s->push(opr);  // sexy part which is req when opr is > inpcoming op, and u need too push it
                    s->push(inp[i]); // explained simple using 1,2,3,4 priority stack
                }
            }
        }
    }

    char rem;
    do{
        rem = s->pop();
        if(rem!= '\0'){
            out = out + rem;
        }
    }while(rem!='\0');
    
    cout<<"Postfix string is "<<out<<endl;
    return 0;
}