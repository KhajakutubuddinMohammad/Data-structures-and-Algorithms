#include<bits/stdc++.h>
#include<list>
using namespace std;


class graph{
  int v,i,s,a;
  list<int> *adj;
  bool *visited;
  public:
  graph(int v)
  {
    this->v=v;
    adj=new list<int>[v];
    visited=new bool[v];
    for(i=0;i<v;i++)
    {
        visited[i]=false;
    }

  }
  void addedge(int u,int w)
  {
     adj[u].push_back(w);
  }
  void dfsutil(int q,bool *visited)
  {
    stack<int> s;
    s.push(q);
    while(!s.empty())
    {
     a=s.top();
     s.pop();
     if(!visited[a])
     {
         cout<<a<<" ";
         visited[a]=true;
     }
     for(auto k=adj[a].begin();k!=adj[a].end();k++)
     {
          if(!visited[*k])
          {
              s.push(*k);
          }
     }
  }
  }
  void dfs(int q)
  {

     dfsutil(q,visited);
     for(i=0;i<v;i++)
     {
         if(!visited[i])
         {
             dfsutil(i,visited);
         }
     }
  }
};
int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(1,4);
    g.addedge(2,4);
    g.addedge(2,3);
    g.addedge(3,4);
    cout<<"the following dfs order is:"<<endl;
    g.dfs(3);
    return 0;
}

/*
1.Time complexity of dfs is O(V+E) and for bfs it is O(V+E)
2.DFS uses stack while BFS uses queue
3.we can use same method above to bfs when graph is disconnected
*/
