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
      //cout<<"hii";
     bool *visited =new bool[v];
     for(i=0;i<=v;i++)
     {
       visited[i]=false;
     }
     /*queue=new list<int>[v];*/
     queue.push_back(q);
     visited[q]=true;
     list<int>:: iterator i;
     int flag=0;
     while(!queue.empty())
     {
         //cout<<"geeks";
       s=queue.front();
       queue.pop_front();
       cout<<s<<"  ";
       for(i=adj[s].begin();i!=adj[s].end();i++)
       {

         if(!visited[*i])
         {
             //cout<<"entered into "<<s;
           visited[*i]=true;
           queue.push_back(*i);
         }
         else{
            //cout<<"loop occurred"<<endl;
            flag=1;
            break;
         }

       }
       if(flag==1)
       {

           cout<<"graph contains cycle\n"<<endl;
           break;
       }

     }

  }

};
int main()
{
    graph g(8);
    g.addedge(1,2);
    g.addedge(1,3);
    g.addedge(2,4);
    g.addedge(3,5);
    g.addedge(5,6);
    g.addedge(7,1);
    g.addedge(6,7);
    cout<<"the following bfs order is:"<<endl;
    g.bfs(1);
    return 0;
}
