#include<iostream>
#include<list>
using namespace std;


class graph
{
  int v,i,s,x;
  list<int> *adj;
  public:
  graph(int v)
  {
    this->v=v;
    adj=new list<int>[v];

  }
  void addedge(int u,int w)
  {  cout<<"hii"<<"   ";
     adj[u].push_back(w);
  }
  void no_of_nodes(int q,int t)
  {
     cout<<"hello\n";
     bool *visited =new bool[v];
     int level[v];
     list<int> queue;
     for(int i=0;i<v;i++)
     {
       visited[i]=false;
       level[i]=0;
     }
     /*queue=new list<int>[v];*/
     queue.push_back(q);
     visited[q]=true;
     list<int>:: iterator itr;
     while(!queue.empty())
     {
       q=queue.front();
       queue.pop_front();
       for(itr=adj[q].begin();itr!=adj[q].end();itr++)
       {
         if(!visited[*itr])
         {
           visited[*itr]=true;
           queue.push_back(*itr);
           level[*itr]=level[q]+1;
         }
       }
     }
     int count=0;
     for(int e=0;e<v;e++)
     {
         if(level[e]==t)
         {
             count+=1;
         }
     }
     cout<<count<<" ";

  }

};
int main()
{
    graph g(9);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,3);
    g.addedge(1,4);
    g.addedge(1,5);
    g.addedge(2,6);
    g.addedge(2,7);
    g.addedge(3,8);
    g.no_of_nodes(0,1);
    return 0;
}

