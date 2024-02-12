#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
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
    int dist[V] = {INT_MAX};
    dist[s] = 0;
    vector<int> sorted(V, 0);
    int indegree[V] = {0};
    for(int i=0;i<V;i++)
    {
        for(int x: adj[i]) indegree[x]++;
    }
    queue<int> q;
    for(int i=0;i<V;i++)
    {
        if(indegree[i]==0) q.push(i);
    }
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        sorted.push_back(u);
        for(int v : adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }
    for(int v : sorted[u])
    {
        if(dist[v]>dist[u]+weight(u, v)) dist[v] = dist[u]+weight(u, v);
    }
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
    cout << "Topological sorting: "<< endl;
    shortestPath(adj, V, 0);
return 0;
}