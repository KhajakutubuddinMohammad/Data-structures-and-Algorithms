#include<bits/stdc++.h>
#include<list>

using namespace std;

class graph
{
    int v,i,j;
    list<int> *adj;
    bool **tc;
    public:
    graph(int v)
    {
        this->v=v;
        adj=new list<int> [v];
        tc=new bool* [v];
        for (int i=0; i<v; i++)
        {
           tc[i] = new bool[v];
           memset(tc[i], false, v*sizeof(bool));
        }
    }
    void addedge(int u,int w)
    {
        adj[u].push_back(w);
    }
    void dfsutil(int u,int w)
    {
        tc[u][w]=1;
        list<int>:: iterator itr;
        for(itr=adj[w].begin();itr!=adj[w].end();itr++)
        {
           if(tc[u][*itr]==false)
           {
             dfsutil(u,*itr);
           }
        }
    }
    void transitive_closure()
    {
        for(i=0;i<v;i++)
        {
            dfsutil(i,i);
        }

    }
    void printgraph()
    {
        for(i=0;i<v;i++)
        {

            for(j=0;j<v;j++)
            {
                cout<<tc[i][j]<<" ";

            }
            cout<<endl;
        }
    }
};

int main()
{
    graph g(3);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,0);
    g.addedge(2,1);
    g.transitive_closure();
    g.printgraph();
    return 0;
}
