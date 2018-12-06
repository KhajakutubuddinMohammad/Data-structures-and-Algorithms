#include<bits/stdc++.h>
using namespace std;

struct graph{
   int v;
   set<int,greater<int> >* adj;
};

graph* creategraph(int v)
{
    graph* g=new graph;
    g->v=v;
    g->adj=new set<int,greater<int> >[v];
    return g;
};
void addedge(graph* g,int u,int w)
{
    g->adj[u].insert(w);
    g->adj[w].insert(u);

};
void printgraph(graph* g,int v)
{
    set<int, greater<int> >:: iterator x;
    for (int i = 0; i < g->v; ++i) {
        unordered_set<int> lst = g->adj[i];
        cout << endl << "Adjacency list of vertex "<< i << endl;

        for (x = lst.begin();x != lst.end();x++)
            cout << *x << " ";
        cout << endl;
    }
};
void searchedge(graph *g,int u,int w)
{
    set<int,greater<int> >::iterator itr;
    itr=g->adj[u].find(w);
    if(itr == g->adj[u].end())
    {
        cout<<"edge not found\n";

    }
    else
    {
        cout<<"edge found\n";
    }

};

int main()
{
    int v=5,i;
    struct graph* g=creategraph(v);
    addedge(g,1,2);
    addedge(g,1,3);
    addedge(g,2,3);
    addedge(g,2,4);
    addedge(g,2,5);
    addedge(g,3,4);
    addedge(g,3,5);
    addedge(g,4,5);
    printgraph(g,v);
    searchedge(g,3,4);
    searchedge(g,1,4);
    return 0;
}
