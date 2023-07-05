#include <iostream>
#include <string.h>

using namespace std;

class PostEval{
    int st[50];
    int top = -1;

    public:
        void push(int data){
            int i;
            top++;
            st[top] = data;
        }

        int pop(){
            return (st[top--]);
        }

        int eval(int d1, int d2, char s){
            int r;
            switch (s){
                case '+':
                    r = d1 + d2;
                    break;

                case '-':
                    r = d1 - d2;
                    break;

                case '*':
                    r = d1 * d2;
                    break;

                case '/':
                    r = d1 / d2;
                    break;

                case '%':
                    r = d1 % d2;
                    break;
            }

            return (r);
        }

        void postEval(string post){
            int i, j, val, opd1, opd2;

            i = post.length();
            for (int j = 0; j < i; j++){
                if ((post[j] == ' ') || (post[j] == '\t')){
                    continue;
                }

                else if (isdigit(post[j])){
                    val = post[j] - 48;
                    push(val);
                }

                else if (isalpha(post[j])){
                    cout << "Enter the value of " << post[j];
                    cin >> val;
                    push(val);
                }

                else{
                    opd2 = pop();
                    opd1 = pop();
                    int x = eval(opd1, opd2, post[j]);
                    push(x);
                }
            }

            cout << "Postfix Evaluation - " << pop();
        }
};


class PreEval{
    int st[50];
    int top = -1;

    public: 
        void push(double c){
            st[++top] = c;
        }

        double pop(){
            return st[top--];
        }

        bool is_operand(char c){
            return isdigit(c);
        }

        void evaluate(string exp){
            double a, b;

            for(int j = exp.size()-1; j>=0; j--){
                if(is_operand(exp[j])){
                    push(exp[j]-'0');
                }

                else{
                    a = st[top];
                    pop();
                    b = st[top];
                    pop();

                    switch(exp[j]){
                        case '+':
                            push(a + b);
                            break;
                        
                        case '-':
                            push(a-b);
                            break;

                        case '*':
                            push(a*b);
                            break;

                        case '/':
                            push(a/b);
                            break;
                    }
                }
            }
            cout<<st[top];
        }
};

int main(){
    PostEval post;
    PreEval pre;
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int choice;
    cout<<"1. Postfix Evaluation"<<endl;
    cout<<"2. Prefix Evaluation"<<endl;
    cout<<"3. Exit"<<endl;

    do{
        cout<<"Enter choice --> ";
        cin>>choice;


        switch (choice){
            case 1 : {
                string inp;
                cout << "Enter the postfix which is to be evaulated - ";
                cin>>inp;
                post.postEval(inp);
                cout<<endl;
                cout<<endl;
                break;
            }

            case 2:{
                string inp;
                cout << "Enter the postfix which is to be evaulated - ";
                cin>>inp;
                pre.evaluate(inp);
                cout<<endl;
                cout<<endl;
                break;
            }
        }
    } while (choice!=3);
    

    
    return 0;
}