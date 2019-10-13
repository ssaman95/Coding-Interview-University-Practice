#include <iostream>
#include <list>
#include <stack>
using namespace std;

class Graph {
    int n; // #vertices
    list<int> *adj;
    void TopologicalSortUtil(int u, bool seen[], stack<int> &s);
    public:
    Graph(int n);
    void AddEdge(int u, int v);
    void TopologicalSort();
};

Graph::Graph(int n) {
    this->n = n;
    adj = new list<int>[n];
}

void Graph::TopologicalSort() {
    bool *seen = new bool[n];
    for (int i = 0; i < n; ++i)
        seen[i] = false;

    stack<int> s;

    for (int i = 0; i < n; ++i)
        if (!seen[i])
            TopologicalSortUtil(i, seen, s);

    cout << "Topological Sort:" << endl;

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

}

void Graph::TopologicalSortUtil(int u, bool seen[],stack<int> &s) {
    seen[u] = true;

    for (auto i = adj[u].begin(); i != adj[u].end(); ++i)
        if (!seen[*i])
            TopologicalSortUtil(*i, seen, s);

    s.push(u);
}

void Graph::AddEdge(int u, int v) {
    adj[u].push_back(v);
}

// Driver program to test above functions 
int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(6); 
    g.AddEdge(5, 2); 
    g.AddEdge(5, 0); 
    g.AddEdge(4, 0); 
    g.AddEdge(4, 1); 
    g.AddEdge(2, 3); 
    g.AddEdge(3, 1); 
  
    g.TopologicalSort(); 
  
    return 0; 
}
