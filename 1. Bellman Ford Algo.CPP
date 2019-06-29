/*
Bellman Ford's algorithm is used to find the shortest paths 
from the source vertex to all other vertices in a weighted graph. 
It depends on the following concept: Shortest path contains at most  edges, 
because the shortest path couldn't have a cycle.
This algorithm depends on the relaxation principle where the shortest distance
for all vertices is gradually replaced by more accurate values until 
eventually reaching the optimum solution.
A very important application of Bellman Ford is to check if there is a negative cycle in the graph.

Time Complexity : O(V.E)
If E=V^2, then time = O(E^3), i.e, O(n^3);

*/


#include<bits/stdc++.h>
#define ll long long int
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define inf 1000000000000000000
#define newln cout<<"\n"
#define MAX5 100005
#define MAX6 1000006
#define MOD 1000000007
#define fastIO ios_base::sync_with_stdio(0);\
               cin.tie(NULL);\
               cout.tie(NULL)

using namespace std;

struct edge
{
	ll from, to;
	ll wt;
};
void bellmanFord(ll n, ll s, vector<edge> edgeList,ll dist[])
{
	for(ll i=0 ; i<n-1 ; i++)
	{
		int flag=0;
		for(auto i:edgeList)
		{
			if(dist[i.from]==inf)
				continue;
			if(dist[i.from] + i.wt < dist[i.to])
			{
				flag=1;
				dist[i.to] = dist[i.from] + i.wt;
			}
		}
		if(flag==0)
			break;
		// cout<<"Iteration : "<<i+1<<endl;
		// for(ll i=1 ; i<=n ; i++)
		// cout<<i<<" : "<<dist[i]<<endl;
	}

}

int main()
{
	fastIO;
	freopen("input.txt","r",stdin);
	

	ll n,m;	//n nodes, m edges
	cin>>n>>m;

	
	vector<edge> edgeList;
	for(ll i=0 ; i<m ; i++)
	{
		ll u, v, cost;	//edge from u to v
		cin>>u>>v>>cost;
		edgeList.push_back({u,v,cost});
	}
	ll dist[n+1];	//will store shortest path from source

	for(ll i=0 ; i<=n ; i++)
		dist[i]=inf;

	ll s;	//source vertex
	cin>>s;
	dist[s]=0;
	bellmanFord(n,s,edgeList,dist);

	
	return 0;
}