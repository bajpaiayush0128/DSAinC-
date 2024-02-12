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

void shortestPath(vector<int> adj[], int V, int s)
{
    bool visited[V];
    int dist[V] = {INT_MAX};
    dist[s] = 0;
    for(int i=0;i<V;i++) visited[i]=false;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v : adj[u])
        {
            if(visited[v]==false)
            {
                dist[v] = dist[u] + 1;
                visited[v] = true;
                q.push(v);
            }
        }
    }
    for(int i=0;i<V;i++) cout << dist[i] << " ";
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
    cout << "Shortest distances: "<< endl;
    shortestPath(adj, V, 0);
return 0;
}