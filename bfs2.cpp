#include<iostream>
#include<list>
using namespace std;


class graph
{
  int v,i,s,x;
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
  void bfs(int q)
  {
     bool *visited =new bool[v];
     for(i=1;i<=v;i++)
     {
       visited[i]=false;
     }
     /*queue=new list<int>[v];*/
     queue.push_back(q);
     visited[q]=true;
     list<int>:: iterator i;
     while(!queue.empty())
     {
       s=queue.front();
       queue.pop_front();
       cout<<s<<"  ";
       for(i=adj[s].begin();i!=adj[s].end();i++)
       {
         if(!visited[*i])
         {
           visited[*i]=true;
           queue.push_back(*i);
         }
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
    g.addedge(3,4);
    g.addedge(3,5);
    g.addedge(4,5);
    cout<<"the following bfs order is:"<<endl;
    g.bfs(1);
    return 0;
}
