//count connected components in an undirected graph
//it will use DFS approach to traverse the graph and the count of times DFS is called will be the count of connected components
//as dfs will marked all nodes of a component as visited in one call
#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
vector<int> g[N];
bool visited[N];
vector<vector<int>> components;
vector<int> current_component;
void dfs(int node)
{
    //perform task on vertex after entering the node
    visited[node]=true;
    current_component.push_back(node);
    cout<<node<<" ";
    for(auto child:g[node])
    {
        //perform task on child before entering the child node
        if(!visited[child])
        {
            current_component.clear();
            dfs(child);
            components.push_back(current_component);
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
    int connected_components=0;
    for(int i=0;i<n;i++)
    {
        if(!visited[i])
        {
            cout<<"DFS Traversal for component "<<connected_components+1<<":"<<endl;
            dfs(i);
            cout<<endl;
            connected_components++;
        }
    }
    cout<<"Number of connected components: "<<connected_components<<endl;
    for(auto comp:components)
    {
        cout<<"Component: ";
        for(auto node:comp)
        {
            cout<<node<<" ";
        }
        cout<<endl;
    }
    return 0;
}