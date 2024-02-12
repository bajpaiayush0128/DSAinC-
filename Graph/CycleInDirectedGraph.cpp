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

bool DFS(vector<int> adj[], int s, bool visited[], bool recSt[])
{
    visited[s] = true;
    recSt[s] = true;
    for(int u : adj[s])
    {
        if(visited[u]==false && DFS(adj, u, visited, recSt)) return true;
        else if(recSt[u]==true) return true;
    }
    recSt[s] = false;
    return false;
}

bool DFSPrint(vector<int> adj[], int V, int s)
{
    bool visited[V];
    for(int i =0;i<V;i++) visited[i] = false;
    bool recSt[V];
    for(int i =0;i<V;i++) recSt[i] = false;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            if(DFS(adj, i, visited, recSt)==true) return true;
        }
    }
    return false;
}


// using kahn's algorithm
bool isCycleBFS(vector<int> adj[], int V)
{
    int indegree[V] = {0};
    int count = 0;
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
        cout << u << " ";
        for(int v : adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
            count++;
        }
    }
    if(count!=V) return true;
    return false;
}

int main()
{
    int V = 4;
    vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 0);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    cout << "Adjecency list: "<< endl;
    printGraph(adj, V);
    cout << "Is Cycle present: "<< DFSPrint(adj, V, 0) << endl;
    cout << "Is Cycle present: "<< isCycleBFS(adj, V) << endl;
return 0;
}