#include <iostream>
using namespace std;
#define MAX 20

void create_graph();
void display();
void dft(int v);
void bft(int v);
void adj_nodes(int v);
int adj[MAX][MAX];
int visited[MAX];
int n; /* Denotes number of nodes in the graph */
int main()
{
    int i, v, choice;
    create_graph();
    while (1)
    {
        cout << "\n";

        cout << "1. Depth First Search using stack\n";
        cout << "2. Breadth First Search\n";
        cout << "3. Exit\n";
        cout << "Enter your choice : ";
        cin >> choice;
        switch (choice)
        {

        case 1:
            cout << "Enter starting node for Depth First Search : ";
            cin >> v;
            for (i = 1; i <= n; i++)
                visited[i] = 0;
            dft(v);
            break;
        case 2:
            cout << "Enter starting node for Breadth First Search : ";
            cin >> v;
            for (i = 1; i <= n; i++)
                visited[i] = 0;
            bft(v);
            break;

        case 3:
            exit(1);
        default:
            cout << "Wrong choice\n";
            break;
        } // End of switch
    }     // End of while/
} // End of main()/

void create_graph()
{
    int i, max_edges, origin, destin;
    cout << "Enter number of nodes : ";
    cin >> n;
    for (i = 1; i <= n; i++)
        adj[i][i] = 1;
    max_edges = n * (n - 1);
    for (i = 1; i <= max_edges; i++)
    {
        cout << "Enter edge origin and destination or ( 0 0 to quit ):";
        cin >> origin >> destin;
        if ((origin == 0) && (destin == 0))
            break;
        if (origin > n || destin > n || origin <= 0 || destin <= 0)
        {
            cout << "Invalid edge!\n";
            i--;
        }
        else
        {
            adj[origin][destin] = 1;
            adj[destin][origin] = 1;
        }
    }
}

void dft(int v)
{
    int i, stack[MAX], top = -1, pop_v, j, t;
    int ch;
    top++;
    stack[top] = v;
    while (top >= 0)
    {
        pop_v = stack[top];
        top--; // pop from stack/
        if (visited[pop_v] == 0)
        {
            cout << pop_v;
            visited[pop_v] = 1;
        }
        // else
        // continue;
        for (i = 1; i <= n; i++)
        {
            if (adj[pop_v][i] == 1 && visited[i] == 0)
            {
                top++; /* push all unvisited neighbours of pop_v */
                stack[top] = i;
            } // End of if/
        }     // End of for/
    }         // End of while/
} // End of dfs()/
void bft(int v)
{
    int i, front, rear;
    int que[20];
    front = rear = -1;
    cout << "" << v;
    visited[v] = 1;
    rear++;
    que[rear] = v;
    while (front <= rear)
    {
        front++;
        if (front <= rear)
            v = que[front]; /* delete from queue */
        for (i = 1; i <= n; i++)
        {
            /* Check for adjacent unvisited nodes */
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                cout << "" << i;
                visited[i] = 1;
                rear++;
                que[rear] = i;
            }
        }
    } // End of while/
} // End of bfs()/