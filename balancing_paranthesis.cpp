#include<iostream>
using namespace std;

class stack{
    public:
        int size, top;
        char *arr;      // pointer variable that will store add of data type char
                        // in this code itll store add of first char of array created dynamically

        void push(char data){
            if( top == size-1){
                cout<<"Array is full"<<endl;
                return;
            }
              top++;
              arr[top] = data;
        }

        char pop(){            
            char val = arr[top];
            top--;
            return val;
        }

        void display(){
            for(int i=0; i<= top; i++){
                cout<< arr[i]<<" ";
            }
            cout<<endl;
        }

        int match(char a, char b){
            if(a=='{' && b=='}'){
                return 1;
            }

            if(a=='(' && b==')'){
                return 1;
            }

            if(a=='[' && b==']'){
                return 1;
            }

            return 0;  
        }
};

int main(){
    stack *s = new stack;
    s->size = 10;
    s->top = -1;
    s->arr = new char[s->size];

    int inp;
    cout<<"Enter the input string : ";
    cin>>inp;

    int check = -1;

    for(int i=0; i<inp.length(); i++){
        if(inp[i]=='(' || inp[i]=='{' || inp[i]=='['){
            s->push(inp[i]);
        }

        else if(inp[i]==')'|| inp[i]=='}' || inp[i]==']'){
            if(s->top==-1){
                check = 0;
            }

            check = s->match(s->pop(), inp[i]);
        }
    }

    if(check==1){
        cout<<"The parenthesis are balanced."<<endl;
    }

    else{
        cout<<"The parenthesis are not balanced."<<endl;
    }
    return 0;
}