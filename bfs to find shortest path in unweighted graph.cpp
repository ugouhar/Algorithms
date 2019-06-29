/*
Since the graph is unweighted, we can solve this problem in O(V + E) time.
The idea is to use a modified version of BFS in which we keep storing
the predecessor of a given vertex while doing the breadth first search.
This algorithm will work even when negative weight cycles are present in the graph.

/////////////////////////////////////////////////////////////////////////////////////////

We first initialize an array dist[0, 1, …., v-1] such that
dist[i] stores the distance of vertex i from the source vertex
and array pred[0, 1, ….., v-1] such that pred[i] represents the
immediate predecessor of the vertex i in the breadth first search
starting from the source.

*/
#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pb push_back
using namespace std;

vll adj[20];
bool visited[20];
ll dist[20]={0};
ll pred[20];

bool bfs(ll s,ll d)
{
    queue<ll> q;
    visited[s]=true;
    q.push(s);
    dist[s]=0;

    while(!q.empty())
    {
        s=q.front();
        q.pop();
        for(ll i=0 ; i<adj[s].size() ; i++)
        {
            ll node=adj[s][i];
            if(!visited[node])
            {
                dist[node]=dist[s]+1;
                pred[node]=s;
                q.push(node);
                visited[node]=true;
                if(node==d)
                    return true;
            }
        }
    }
    return false;
}
void addEdge(ll a,ll b)
{
    adj[a].pb(b);
    adj[b].pb(a);
}

void initialize()
{
    for(ll i=0 ; i<20 ; i++)
    {
        visited[i]=false;
        dist[i]=LLONG_MAX;
        pred[i]=-1;
    }

}
int main()
{
    ll edges[][2]={
                    {1,2},
                    {1,3},
                    {2,4},
                    {2,5},
                    {2,3},
                    {3,6},
                    {3,7},
                    {4,8},
                    {4,9},
                    {4,10},
                    {5,11},
                    {7,12},
                    {7,13}
                  };
    for(ll i=0 ; i<13 ; i++)
    addEdge(edges[i][0],edges[i][1]);
    initialize();

    ll s,d;
    cout<<"Enter source and destination : ";
    cin>>s>>d;
    if(bfs(s,d))
    {
        cout<<"Shortest path length : "<<dist[d]<<endl;
        cout<<"Path : ";
        vll path;
        while(d!=s)
        {
            path.pb(d);
            d=pred[d];
        }
        path.pb(s);
        for(ll i=path.size()-1 ; i>=0 ; i--)
            cout<<path[i]<<' ';
    }
    else
        cout<<"Not connected";
    return 0;
}
