#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define max1 1000006
using namespace std;
 
ll par[max1];
ll size[max1];
vector<pll> adj[max1];
bool vis[max1];

struct comp 
{
    bool operator()(pll a,pll b) 
    {
        return a.first>b.first;
    }
};

void initialize()
{
	for(int i=0 ; i<max1 ; i++)
	{
		par[i]=i;
		size[i]=1;
		adj[i].clear();
		vis[i]=false;
	}
}

ll root(ll x)
{

	if (x==par[x])
		return x;
	return par[x]=root(par[x]);
}
void unionab(int a,int b)
{
	int ra=root(a);
	int rb=root(b);
	if(ra==rb)
		return;
	if(size[ra]>size[rb])
		swap(ra,rb);
	par[rb]=par[ra];
	size[ra]+=size[rb];
}

ll prims(ll x)
{
	ll cost=0;
	priority_queue<pll,vector<pll>,comp> q;
	q.push({0,x});
	while(!q.empty())
	{
		pll curr=q.top();
		q.pop();
		ll x=curr.second;
		if(vis[x]==true)
			continue;

		vis[x]=true;
		cost+=curr.first;
		
		for(auto node:adj[x])
		{
			if(!vis[node.second])
			{
				q.push({node.first,node.second});
			}
		}
	}
	return cost;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

 	initialize();

    freopen("input.txt","r",stdin);
    ll n,m;
    cin>>n>>m;

    for(ll i=0 ; i<m ; i++)
    {
    	ll a,b,c;
    	cin>>a>>b>>c;
    	adj[a].pb({c,b});
    	adj[b].pb({c,a});
    }

 	ll c=prims(1);
 	cout<<c;
 
	return 0;
	//Always comment out input.txt
}
