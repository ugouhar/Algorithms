#include<bits/stdc++.h>

#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define pb push_back


using namespace std;

vll adj[10001];

bool vis[10001];
ll val[10001]={0};
ll maxm=-1,leaf;
ll dfs(ll curr)
{
    vis[curr]=true;
        for(ll i=0 ; i<adj[curr].size() ; i++)
        {
            ll node=adj[curr][i];
            if(!vis[node])
            val[curr]+=dfs(node)+val[node];
        }
    return 1;
}

void addEdge(ll a,ll b)
{
    adj[a].pb(b);
    adj[b].pb(a);
}
void initialize()
{
    for(ll i=0 ; i<=10000 ; i++)
        vis[i]=false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);cout.tie(NULL);
    initialize();

    ll n,a,b,s;
    cin>>n;
    cin>>a>>b;
    addEdge(a,b);
    s=a;
    for(ll i=1 ; i<n-1 ; i++)
    {
        cin>>a>>b;
        addEdge(a,b);
    }
    dfs(1);
    for(ll i=1 ; i<=14 ; i++)
        cout<<i<<" : "<<val[i]<<endl;
    return 0;
}

/*
14
1 2
1 3
2 4
2 5
2 6
5 7
5 8
3 9
9 10
9 11
10 12
10 13
10 14
*/


