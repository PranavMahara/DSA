#include<iostream>
#include<string>  
using namespace std;
#define MAX 30

class post
{
    char a[MAX]; // As the expression contains operators & operands, use a char array
    int top = -1;

public:
    void push(char data)
    {
        top++;
        a[top] = data;
    }

    char pop()
    {
        if (top != -1)
        {
            int x = a[top];
            top--; // normal stack ka operation
            return x;
        }

        else
        {
            return ('\0');
        }
    }

    int priority(char data)
    { // yeh vala priority check karne ke liye
        if (data == '*' || data == '/' || data == '%')
        {
            return 3;
        }

        else if (data == '-' || data == '+')
        {
            return 2;
        }

        else if (data == '>' || data == '<')
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    string pre(string s)
    {
        string post;
        char opr;
        int len = s.length();

        for (int j = 0; j < len; j++)
        {
            if ((s[j] == ' ') || (s[j] == '\t'))
                continue;
            else if ((isdigit(s[j])) || (isalpha(s[j])))
            {

                post.append(1, s[j]);
            }
            else if (s[j] == '(')
                push(s[j]);
            else if (s[j] == ')')
            {
                do
                {
                    opr = pop();
                    if (opr == '(')
                        break;
                    else
                        post.append(1, opr);
                } while (opr != '(');
            }
            else
            {
                if (top == -1)
                    push(s[j]);
                else
                {
                    opr = pop();
                    if (opr == '(')
                    {
                        push(opr);
                        push(s[j]);
                    }
                    else
                    {
                        while (priority(opr) >= priority(s[j]))
                        {
                            post.append(1, opr);
                            opr = pop();
                            if (opr == '\0')
                                break;
                        }
                        push(opr);
                        push(s[j]);
                    }
                }
            }
        }
        char x;
        do
        {
            x = pop();
            if (x != '\0')
                post.append(1, x);
        } while (x != '\0');
        post.append(1, '\0');
        return post;
    }

    void infixToPrefix(string x)
    {
        int n = x.length();
        for (int i = 0; i < n / 2; i++)
        {
            swap(x[i], x[n - i - 1]);
        }

        int i = 0;
        while (x[i] != '\0')
        {
            if (x[i] == '(')
            {
                x[i] = ')';
            }

            else if (x[i] == ')')
            {
                x[i] = '(';
            }
            i++;
        }
        // cout << x << endl;

        string new_str;
        new_str = pre(x);
        // cout<<new_str<<endl;
        cout<<"postfix expressison : ";
        for (int i=n; i>=0; i--)
        {   
            cout<<new_str[i];
        }
    }
};
int main()
{
    post p;
    cout<<"Done by - \nPranav Singh Mahara \n21BBS0188"<<endl;
    int choice;
    cout << "1. Infix to Postfix" << endl;
    cout << "2. Infix to Prefix" << endl;
    cout << "3. Exit" << endl;

    do
    {
        cout << "Enter choice --> ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string inp;
            cout << "infix expression - ";
            cin >> inp;
            cout << "postfix expression : " <<p.pre(inp);
            cout << endl;
            cout << endl;
            break;
        }

        case 2:
        {
            string inp;
            cout << "infix expression - ";
            cin >> inp;
            p.infixToPrefix(inp);
            cout<<endl;
            cout<<endl;
            break;
        }
        }
    } while (choice != 3);

    // p.infixToPrefix("(A-B/C)*(A/K-L)");
    return 0;
}