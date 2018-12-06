#include<iostream>
#include<bits/stdc++.h>
#include<list>
using namespace std;


class graph{
  int v,i,s;
  list<int> *adj;
  list<int> queue;
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
  int dfsutil(int q,bool *visited)
  {
      visited[q]=true;
      cout<<q<<" ";
      list<int>::iterator k;
      for(k=adj[q].begin();k!=adj[q].end();k++)
      {

        if(visited[*k])
        {

            cout<<"loop occurred\n";
            return 0;

        }
        else
        {
            //cout<<"entered into else block\n";
            int a=dfsutil(*k,visited);
            if(a == 0)
                return 0;
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
    bool *visited=new bool[5];
    memset(visited,false,sizeof(visited));
    int a=g.dfsutil(1,visited);
    return 0;
}

/*
1.Time complexity of dfs is O(V+E) and for bfs it is O(V+E)
2.DFS uses stack while BFS uses queue
3.we can use same method above to bfs when graph is disconnected
*/
