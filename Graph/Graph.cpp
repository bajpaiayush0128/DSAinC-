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

void BFS(vector<int> adj[], int V, int s)
{
    bool visited[V];
    for(int i=0;i<V;i++) visited[i]=false;
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        cout << u << " ";
        for(int v : adj[u])
        {
            if(visited[v]==false)
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }
}

// BFS without source and graph may be disconnected
// in the above BFS function, pass visited as func argument to make this func work
// void BFSDisconnected(vector<int> adj[], int V)
// {
//     bool visited[V+1];
//     for(int i=0;i<V;i++) visited[i] = false;
//     for(int i=0;i<V;i++)
//     {
//         if(visited[i]==false) BFS(adj, V, i, visited);
//     }
// }

// int pairOfConnectedComponents(vector<int> adj[], int V)
// {
//     int count = 0;
//     bool visited[V+1];
//     for(int i=0;i<V;i++) visited[i] = false;
//     for(int i=0;i<V;i++)
//     {
//         if(visited[i]==false) BFS(adj, V, i, visited);
//         count++;
//     }
//     return count;
// }

void DFS(vector<int> adj[], int s, bool visited[])
{
    visited[s] = true;
    cout << s << " ";
    for(int u : adj[s])
    {
        if(visited[u]==false) DFS(adj, u, visited);
    }
}

void DFSPrint(vector<int> adj[], int V, int s)
{
    bool visited[V];
    for(int i =0;i<V;i++) visited[i] = false;
    DFS(adj, s, visited);
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
    cout << "BFS: "<< endl;
    BFS(adj, V, 3);
    // BFSDisconnected(adj, V);
    cout << "\nDFS: "<<endl;
    DFSPrint(adj, V, 3);
return 0;
}