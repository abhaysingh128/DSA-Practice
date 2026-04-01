#include<bits/stdc++.h>
using namespace std;
vector<int> topoSort(int n, vector<int> g[]) {
   vextor<int>vis (n,0);
   stack<int>st;
    for(int i=0;i<n;i++){
         if(!vis[i]){
              dfs(i,vis,g,st);
         }
    }
    vector<int>ans;
    while(!st.empty()){
         ans.push_back(st.top());
         st.pop();
    }
    return ans;
}
void dfs(int node,vector<int>&vis,vector<int>g[],stack<int>&st){
     vis[node]=1;
     for(auto child:g[node]){
          if(!vis[child]){
               dfs(child,vis,g,st);
          }
     }
     st.push(node);
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
    
    vector<int> result = topoSort(n, g);
    cout << "Topological Sort Order: ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;
    return 0;
}