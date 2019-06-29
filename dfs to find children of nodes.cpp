
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
#define MAX 10000
using namespace std;

bool visited[20];
vll adj[20];
ll nchild[20]={0};

ll dfs(ll s)
{
    visited[s]=true;
    if(adj[s].size()==0)
        return 1;
    for(ll i=0 ; i<adj[s].size() ; i++)
    {
        ll node=adj[s][i];
        if(!visited[node])
        nchild[s]+=dfs(node)+1;
    }

    return adj[s].size();
}

void addEdge(ll a,ll b)
{
    adj[a].pb(b);
    adj[b].pb(a);
}

void initialize()
{
    for(ll i=0 ; i<20 ; i++)
        visited[i]=false;
}
int main()
{
    initialize();
    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(3,6);
    addEdge(3,7);
    addEdge(4,8);
    addEdge(4,9);
    addEdge(4,10);
    addEdge(5,11);
    addEdge(11,14);
    addEdge(7,12);
    addEdge(7,13);
    addEdge(12,15);
    addEdge(12,16);
    dfs(1);
    for(ll i=1 ; i<=16 ; i++)
        cout<<i<<" : "<<nchild[i]<<endl;
    return 0;
}
