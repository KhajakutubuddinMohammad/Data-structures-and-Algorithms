#include<iostream>
#include<list>
using namespace std;


class graph{
  int v,i,s;
  list<int> *adj;
  list<int> queue;
  list<int>::iterator k;
  bool *visited=new bool[v];
  public:
  graph(int v)
  {
    this->v=v;
    adj=new list<int>[v];

  }
  void addedge(int u,int w)
  {
     adj[u].push_back(w);
  }
  void dfsutil(int q,bool *visited)
  {
      visited[q]=true;
      cout<<q<<" ";

      for(k=adj[q].begin();k!=adj[q].end();k++)
      {
        if(!visited[*k])
        {
           dfsutil(*k,visited);
        }
      }

  }
  void dfs(int q)
  {

     dfsutil(q,visited);
     for(i=1;i<=v;i++)
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
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,3);
    g.addedge(2,4);
    g.addedge(2,5);
    g.addedge(3,1);
    g.addedge(3,4);
    g.addedge(4,5);
    cout<<"the following dfs order is:"<<endl;
    g.dfs(1);
    return 0;
}

/*
1.Time complexity of dfs is O(V+E) and for bfs it is O(V+E)
2.DFS uses stack while BFS uses queue
3.we can use same method above to bfs when graph is disconnected
*/
