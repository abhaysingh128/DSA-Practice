#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> g[N];
bool visited[N];
void dfs(int node)
{
    //perform task on vertex after entering the node
    visited[node]=true;
    cout<<node<<" ";
    for(auto child:g[node])
    {
        //perform task on child before entering the child node
        if(!visited[child])
        {
            dfs(child);
            //perform task on child after exiting the child node
        }
    }
    //perform task on vertex before exiting the node
}
int main()
{
    int n,e;
    cout<<"Enter number of nodes and edges: ";
    cin>>n>>e;
    cout<<"Enter edges (u v) format:"<<endl;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u); //for undirected graph
    }
    cout<<"DFS Traversal starting from node 0:"<<endl;
    dfs(0);
    cout<<endl;
    return 0;
}