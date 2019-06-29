#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
using namespace std;

vll adj[100000];
bool vis[100000];
ll t;
int flag=0;
void initialize()
{
    for(ll i=0 ; i<100000 ; i++)
        vis[i]=false;
}
void addEdge(ll a,ll b)
{
    adj[a].pb(b);
    adj[b].pb(a);
}
void dfs(ll s)
{
    vis[s]=true;
    cout<<s<<' ';
    for(ll i=0 ; i<adj[s].size() ; i++)
    {
        ll node=adj[s][i];
        if(!vis[node])
        dfs(node);
    }
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
    dfs(1);


    return 0;
}
