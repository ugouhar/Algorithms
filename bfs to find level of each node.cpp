#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
using namespace std;

vll adj[20];
bool visited[20];
ll level[20]={0};

void bfs(ll s)
{
    queue<ll> q;
    visited[s]=true;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        cout<<s<<' '<<level[s]<<endl;
        for(ll i=0 ; i<adj[s].size() ; i++)
        {
            ll node=adj[s][i];
            if(!visited[node])
            {
                level[node]=level[s]+1; // level(child)=level(parent)+1
                q.push(node);
                visited[node]=true;
            }
        }

    }
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
    ll edges[][2]={
                    {1,2},
                    {1,3},
                    {2,4},
                    {2,5},
                    {3,6},
                    {3,7},
                    {4,8},
                    {4,9},
                    {4,10},
                    {5,11},
                    {7,12},
                    {7,13}
                  };
    for(ll i=0 ; i<12 ; i++)
    addEdge(edges[i][0],edges[i][1]);

    bfs(2);
    return 0;
}
