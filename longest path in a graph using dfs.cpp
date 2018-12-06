#include<iostream>
#include<list>
#include<bits/stdc++.h>

using namespace std;


class graph{
  int v,i,s,z=0,count=0;
  list<int> *adj;
  list<int> queue;
  list<int>::iterator k;
  bool *visited;
  public:
  graph(int v)
  {
    this->v=v;
    adj=new list<int>[v];
    visited=new bool[v];

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
            cout<<"hello";
           count+=1;
           dfsutil(*k,visited);

        }
      }
      if(z<=count)
      {
          z=count;
      }
      count=0;

      cout<< z <<endl;

  }
  void dfs()
  {
     memset(visited,false,sizeof(visited));
     dfsutil(0,visited);
  }

};
int main()
{
    graph g(5);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(2,3);
    g.addedge(2,4);
    g.addedge(4,5);
    g.dfs();
    //cout<<"the following dfs order is:"<<endl;
    return 0;
}

/*
1.Time complexity of dfs is O(V+E) and for bfs it is O(V+E)
2.DFS uses stack while BFS uses queue
3.we can use same method above to bfs when graph is disconnected
*/

