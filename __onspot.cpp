/* done by
    Pranav Singh Mahara
    21BBS0188
*/

// Array represnation of Queue to create a binary tree

#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class queue
{
    int a[MAX];      // taking input of elements in tree as string 

    int r, f, n;

public:

    void init(int d)        // initialising variables to required numbers 
    {
        r = -1;
        f = -1;
        n = d;
    }

    void enqueue()          
    {
        if (r = -1)         // adding root node of "0"
        {
            a[0] = "0";
            r++;
        }

        for (int i = 0; i < n; i++)     // adding all elements of queue using for loop
        {                               // using logic of array represnetaion of a Binary tree to insert elements
            int temp1=a[i],temp2=a[i];
            temp1.append("0");temp2.append("1");
            a[2 * i + 1] = temp1;
            a[2 * i + 2] = temp2;
        }
    }

    void level_order()      // basic display function as displaying elements normally gives level order traversal
    {                       // of the binary tree
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

};

int main()
{
    queue q;
    int d;
    cout<<"Done by : \n\t Pranav Singh Mahara\n\t 21BBS0188 "<<endl;
    cout<<"Enter number of nodes : ";
    cin>>d;
    q.init(d);
    q.enqueue();
    cout<<"The level order traversal of the given binary tree of "<<d<<" elements  is : "<<endl;
    q.level_order();

    return 0;
}
