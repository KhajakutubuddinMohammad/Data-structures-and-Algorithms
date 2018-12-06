// C++ program to find K-Cores of a graph
#include<bits/stdc++.h>
using namespace std;

// This class represents a undirected graph using adjacency
// list representation
class Graph
{
    int V;    // No. of vertices

    // Pointer to an array containing adjacency lists
    list<int> *adj;
public:
    Graph(int V);  // Constructor

    // function to add an edge to graph
    void addEdge(int u, int v);

    // A recursive function to print DFS starting from v
    bool DFSUtil(int, vector<bool> &, vector<int> &, int k);

    // prints k-Cores of given graph
    void printKCores(int k);
};

// A recursive function to print DFS starting from v
bool Graph::DFSUtil(int v, vector<bool> &visited, vector<int> &degree, int k)
{
    // Mark the current node as visited and print it
    visited[v] = true;

    // Recur for all the vertices adjacent to this vertex
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
    {
        if (degree[v] < k)
            degree[*i]--;
        if (!visited[*i])
        {
            bool res = DFSUtil(*i, visited, degree, k);
            if (res == true)
                degree[v]--;
        }
    }

    return (degree[v] < k);
}

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

// Prints k cores of an undirected graph
void Graph::printKCores(int k)
{
    // INITIALIZATION
    // Mark all the vertices as not visited and not
    // processed.
    vector<bool> visited(V, false);
    vector<bool> processed(V, false);

    // Store degrees of all vertices
    vector<int> degree(V);
    for (int i=0; i<V; i++)
        degree[i]  = adj[i].size();

    // DFS
    for (int i=0; i<V; i++)
    {
        if (visited[i] == false)
        {
            if (DFSUtil(i, visited, degree, k))
                degree[i]--;
        }
    }

    // PRINTING K CORES
    cout << "K-Cores : \n";
    for (int v=0; v<V; v++)
    {
        // Only considering those vertices which have degree
        // >= K after BFS
        if (degree[v] >= k)
        {
            cout << "\n[" << v << "]";

            // Traverse adjacency list of v and print only
            // those adjacent which have degree >= k after
            // BFS.
            list<int>::iterator itr;
            for (itr = adj[v].begin(); itr != adj[v].end(); ++itr)
                if (degree[*itr] >= k)
                    cout << " -> " << *itr;
        }
    }
}

// Driver program to test methods of graph class
int main()
{
    // Create a graph given in the above diagram
    int k = 3;
    Graph g1(9);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 5);
    g1.addEdge(2, 3);
    g1.addEdge(2, 4);
    g1.addEdge(2, 5);
    g1.addEdge(2, 6);
    g1.addEdge(3, 4);
    g1.addEdge(3, 6);
    g1.addEdge(3, 7);
    g1.addEdge(4, 6);
    g1.addEdge(4, 7);
    g1.addEdge(5, 6);
    g1.addEdge(5, 8);
    g1.addEdge(6, 7);
    g1.addEdge(6, 8);
    g1.printKCores(k);

    cout << endl << endl;

    Graph g(13);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(0, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(1, 6);
    g.addEdge(2, 7);
    g.addEdge(2, 8);
    g.addEdge(2, 9);
    g.addEdge(3, 10);
    g.addEdge(3, 11);
    g.addEdge(3, 12);
    g.printKCores(k);

    return 0;
}

