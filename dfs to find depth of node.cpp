#include<bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

vll adj[2001];
bool vis[2001];

void dfs(ll curr,ll cnt)
{
    vis[curr]=true;
    cout<<curr<<" : "<<cnt<<endl;
    for(ll i=0 ; i<adj[curr].size() ; i++)
    {
        ll node=adj[curr][i];
        if(!vis[node])
        {
            dfs(node,cnt+1);
        }
    }
}
void addEdge(ll a,ll b)
{
    adj[a].pb(b);
}
void initialize()
{
    for(ll i=0 ; i<=2000 ; i++)
        vis[i]=false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    initialize();

    addEdge(1,2);
    addEdge(1,3);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(2,6);
    addEdge(3,9);
    addEdge(5,7);
    addEdge(5,8);
    addEdge(9,10);
    addEdge(9,11);
    addEdge(10,12);
    addEdge(10,13);
    addEdge(10,14);
    dfs(1,0);
    return 0;
}

