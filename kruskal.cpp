#include <iostream>
using namespace std;
#define MAX 30

int set[MAX];
int n;

class edge{
    public:
        int u, v, w;
        void updateset(int c1, int c2){
            for (int i = 0; i <= n; i++)
                if (set[i] == c1){
                    set[i] = c2;
                }
        }
};

int main(){
    edge elist[MAX];
    int i, j, s, d, w, total_cost = 0, n_edges, e1, e2;

    cout<<"Enter the number of vertices : ";
    cin>>n;

    n_edges = n * (n - 1);

    for (i = 0; i < n_edges; i++){
        cout<<"Enter source, destination and cost : ";
        cin>>s>>d;

        if (s == 0 && d == 0){
            break;
        }

        else{
            cout<<"Enter the weight : ";
            cin>>w;
            elist[i].u = s;
            elist[i].v = d;
            elist[i].w = w;
        }
    }

    n_edges = i;
    edge temp;

    for (i = 0; i < n_edges - 1; i++)
        for (j = i + 1; j < n_edges; j++)
            if (elist[i].w > elist[j].w){
                temp = elist[j];
                elist[j] = elist[i];
                elist[i] = temp;
            }
    for (i = 0; i < n_edges; i++){
        cout<<elist[i].u<<" "<<elist[i].v<<" "<<elist[i].w;
    }

    cout<<"Spanning trees "<<n_edges<<" edges "<<endl;
    for (i = 0; i <= n; i++){
        set[i] = i;
    }

    int added_edges = 0;

    for (i = 0; i < n_edges; i++){
        e1 = set[elist[i].u];
        e2 = set[elist[i].v];

        if (e1 != e2){
            cout<<elist[i].u<<" "<<elist[i].v<<" "<<elist[i].w;
            added_edges++;
            temp.updateset(e1, e2);
            total_cost += elist[i].w;
        }

        if (added_edges >= n - 1){
            break;
        }
    }

    cout<<total_cost<<endl;

    return 0;
}