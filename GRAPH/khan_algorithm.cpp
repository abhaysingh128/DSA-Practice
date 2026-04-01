#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(int n, vector<int> g[]) {
    vector<int> indegree(n, 0);
    for (int i = 0; i < n; i++) {
        for (auto child : g[i]) {
            indegree[child]++;
        }
    }
    
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }
    
    vector<int> topo_order;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        topo_order.push_back(node);
        
        for (auto child : g[node]) {
            indegree[child]--;
            if (indegree[child] == 0) {
                q.push(child);
            }
        }
    }
    
    if (topo_order.size() != n) {
        cout << "Graph has a cycle, topological sort not possible." << endl;
        return {};
    }
    
    return topo_order;
}
int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;
    vector<int> g[n];
    cout << "Enter edges (u v) format:" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v); // for directed graph
    }
    
    vector<int> topo_order = topoSort(n, g);
    if (!topo_order.empty()) {
        cout << "Topological Sort Order: ";
        for (auto node : topo_order) {
            cout << node << " ";
        }
        cout << endl;
    }
    
    return 0;
}
