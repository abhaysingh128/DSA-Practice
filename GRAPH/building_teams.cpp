#include<bits/stdc++.h>
using namespace std;
bool dfs(int node, vector<int> &visited, vector<int> g[], vector<int> &team, int curr_team) {
    visited[node] = 1;
    team[node] = curr_team;
    for (auto child : g[node]) {
        if (visited[child] == 0) {
            if (!dfs(child, visited, g, team, 1 - curr_team)) {
                return false;
            }
        } else if (team[child] == team[node]) {
            return false;
        }
    }
    return true;
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
        g[u].push_back(v);
        g[v].push_back(u); // for undirected graph
    }
    
    vector<int> visited(n, 0);
    vector<int> team(n, -1);
    bool is_bipartite = true;
    
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (!dfs(i, visited, g, team, 0)) {
                is_bipartite = false;
                break;
            }
        }
    }
    
    if (is_bipartite) {
        cout << "The graph is bipartite. Teams can be formed as follows:" << endl;
        cout << "Team 0: ";
        for (int i = 0; i < n; i++) {
            if (team[i] == 0) {
                cout << i << " ";
            }
        }
        cout << endl << "Team 1: ";
        for (int i = 0; i < n; i++) {
            if (team[i] == 1) {
                cout << i << " ";
            }
        }
        cout << endl;
    } else {
        cout << "The graph is not bipartite. Teams cannot be formed." << endl;
    }
    
    return 0;
}