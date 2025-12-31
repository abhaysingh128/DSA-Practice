#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
vector<int> g[N];
bool visited[N];
bool dfs(int node, int parent)
{
    visited[node]=true;
    for(auto child:g[node])
    {
        if(!visited[child])
        {
            if(dfs(child,node))
                return true;
        }
        else if(child!=parent)
        {
            return true;
        }
    }
    return false;
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
    bool cycle_found=false;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i,-1))
            {
                cycle_found=true;
                break;
            }
        }
    }
    if(cycle_found)
        cout<<"Cycle found in the graph."<<endl;
    else
        cout<<"No cycle found in the graph."<<endl;
    return 0;
}