#include<bits/stdc++.h>
#define ll long long int
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define inf 1000000000000000000
#define fastIO ios_base::sync_with_stdio(0);\
               cin.tie(NULL);\
               cout.tie(NULL)

using namespace std;



vector<pll> adj[10004];
bool vis[10004];
priority_queue<pll,vector<pll>,greater<pll>> pq;
ll dist[10004];


void relax(ll curr)
{
	if(vis[curr])
			return;
	vis[curr]=true;

	for(auto i:adj[curr]) 
	{
		if(!vis[i.second])
		{
			if(dist[curr]+i.first < dist[i.second])
			{
				dist[i.second] = dist[curr]+i.first;
				pq.push({dist[i.second],i.second});
			}
		}
	}	
}


void dijktra(ll n,ll s)
{
	dist[s]=0;
	pq.push({0,s});

	while(!pq.empty())
	{
		ll curr=pq.top().second;
		pq.pop();
		relax(curr);	
	}
}




int main()
{
	fastIO;
	freopen("input.txt","r",stdin);
	

	ll n,m;	//n nodes, m edges
	cin>>n>>m;


	for(ll i=0 ; i<m ; i++)
	{
		ll u, v, cost;	//edge from u to v
		cin>>u>>v>>cost;
		adj[u].pb({cost,v});
	}


	for(ll i=0 ; i<=n ; i++)	//initializatoin 1
	{
		vis[i]=false;
		dist[i]=inf;
	}

	ll s;	//source vertex
	s=1;
	dijktra(n,s);

	for(ll i=2 ; i<=n ; i++)
	{
		cout<<dist[i]<<' ';
	}
	
	return 0;
}