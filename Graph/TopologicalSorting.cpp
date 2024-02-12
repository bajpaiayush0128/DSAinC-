// Kahn's algorithm(BFS based)

#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<list>
using namespace std;

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    // adj[v].push_back(u);
}

void printGraph(vector<int> adj[], int V)
{
    for(int i=0;i<V;i++)
    {
        for(int x: adj[i]) cout << x << " ";
        cout << "\n";
    }
}

void topologicalSorting(vector<int> adj[], int V)
{
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
        cout << u << " ";
        for(int v : adj[u])
        {
            indegree[v]--;
            if(indegree[v]==0) q.push(v);
        }
    }
}


// topological sorting using DFS
void topologicalSortUtil(vector<int> adj[], int s, bool visited[], stack<int> st)
{
    visited[s] = true;
    for (auto it: adj[s]) {
      if (!visited[it]) topologicalSortUtil(adj, it, visited, st);
    }
    st.push(s);
}

void DFSPrint(vector<int> adj[], int V)
{
    stack<int> st;
    bool visited[V];
    for(int i =0;i<V;i++) visited[i] = false;
    for(int i=0;i<V;i++)
    {
        if(visited[i]==false)
        {
            topologicalSortUtil(adj, i, visited, st);
        }
    }
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
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
    topologicalSorting(adj, V);
    cout << "\nTopological sorting using DFS: "<< endl;
    DFSPrint(adj, V);
return 0;
}