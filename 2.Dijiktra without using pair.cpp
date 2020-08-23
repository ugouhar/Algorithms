// #include<bits/stdc++.h>
// #define ll long long int
// #define pll pair<ll,ll>
// #define vll vector<ll>
// #define pb push_back
// #define inf 1000000000000000000
// #define fastIO ios_base::sync_with_stdio(0);\
//                cin.tie(NULL);\
//                cout.tie(NULL)

// using namespace std;



// vll adj[10004];
// vll w[10004];
// bool vis[10004];
// priority_queue<pll,vector<pll>,greater<pll>> pq;
// ll dist[10004];


// void relax(ll k)
// {
// 	if(vis[k])
// 			return;
// 	vis[k]=true;

// 	for(ll i=0 ; i<adj[k].size() ; i++) 
// 	{
// 		if(!vis[adj[k][i]])
// 		{
// 			if(dist[k]+w[k][i] < dist[adj[k][i]])
// 			{
// 				dist[adj[k][i]] = dist[k]+w[k][i];
// 				pq.push({dist[adj[k][i]],adj[k][i]});
// 			}
// 		}
// 	}	
// }


// void dijktra(ll n,ll s)
// {
// 	dist[s]=0;
// 	pq.push({0,s});

// 	while(!pq.empty())
// 	{
// 		ll curr=pq.top().second;
// 		pq.pop();
// 		relax(curr);	
// 	}
// }




// int main()
// {
// 	fastIO;
// 	freopen("input.txt","r",stdin);
	

// 	ll n,m;	//n nodes, m edges
// 	cin>>n>>m;


// 	for(ll i=0 ; i<m ; i++)
// 	{
// 		ll u, v, cost;	//edge from u to v
// 		cin>>u>>v>>cost;
// 		adj[u].pb(v);
// 		w[u].pb(cost);
// 	}


// 	for(ll i=0 ; i<=n ; i++)	//initializatoin 1
// 	{
// 		vis[i]=false;
// 		dist[i]=inf;
// 	}

// 	ll s;	//source vertex
// 	s=1;
// 	dijktra(n,s);

// 	for(ll i=2 ; i<=n ; i++)
// 	{
// 		cout<<dist[i]<<' ';
// 	}
	
// 	return 0;
// }