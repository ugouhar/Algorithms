/*
	Floyd Warshall's Algorithm is used to find the shortest paths 
	between between all pairs of vertices in a graph, where each edge 
	in the graph has a weight which is positive or negative. 
	The biggest advantage of using this algorithm is that all the 
	shortest distances between any 2 vertices could be calculated 
	in O(V^3) , where V is the number of vertices in a graph.
*/

#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define pll pair<ll,ll>
#define vll vector<ll>
#define pb push_back
#define MAX5 100005
#define inf 1000000000000000000
#define fastIO ios_base::sync_with_stdio(0);\
               cin.tie(NULL);\
               cout.tie(NULL)
using namespace std;

void print(ll arr[][11],ll n, ll m)
{
	for(ll i=1 ; i<=n ; i++)
	{
		for(ll j=1 ; j<=m ; j++)
			cout<<arr[i][j]<<' ';
		cout<<endl;
	}
	cout<<endl;
}

ll adj[11][11];


void init(ll n)
{
	for(ll i=0 ; i<=n ; i++)
	{
		for(ll j=0 ; j<=n ; j++)
		{
			adj[i][j]=inf;
		}
	}
	for(ll i=1 ; i<=n ; i++)
		adj[i][i]=0;
}


void floydWarshall(ll n)
{

	for(ll k=1 ; k<=n ; k++)
	{
		for(ll i=1 ; i<=n ; i++)
		{
			for(ll j=1 ; j<=n ; j++)
			{
				adj[i][j] = min(adj[i][j] , adj[i][k]+adj[k][j]);
			}
		}
	}
	print(adj,4,4);


}
int main()
{
	fastIO;
	freopen("input.txt","r",stdin);
	
	init(10);

	ll n,m;	//n nodes, m edges
	cin>>n>>m;

	for(ll i=0 ; i<m ; i++)
	{
		ll u, v, cost;	//edge from u to v
		cin>>u>>v>>cost;
		adj[u][v]=cost;
	}

	floydWarshall(n);

	return 0;
}
