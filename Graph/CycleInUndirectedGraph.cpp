#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for(int i=0;i<V;i++)
    {
        for(int x: adj[i]) cout << x << " ";
        cout << "\n";
    }
}

bool DFS(vector<int> adj[], int s, bool visited[], int parent)
{
    visited[s] = true;
    for(int u : adj[s])
    {
        if(visited[u]==false)
        {
            if(DFS(adj, u, visited, s)==true) return true;
        } 
        else if(u!=parent) return true;
    }
    return false;
}

bool DFSPrint(vector<int> adj[], int V, int s)
{
    bool visited[V];
    for(int i =0;i<V;i++) visited[i] = false;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(DFS(adj, i, visited, -1)==true) return true;
        }
    }
    return false;
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    cout << "Adjecency list: "<< endl;
    printGraph(adj, V);
    cout << "Is Cycle present: "<< DFSPrint(adj, V, 0) << endl;
return 0;
}