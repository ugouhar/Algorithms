#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define pll pair<ll,ll>
#define pb push_back
#define max1 1000006
using namespace std;
 
int par[max1];
int size[max1];
struct edge
{
	int a,b;
	ll wt;
};
 
bool comp(edge n1,edge n2)
{
	if(n1.wt==n2.wt)
		return n1.a<n2.a;
	return n1.wt<n2.wt;
}
void initialize()
{
	for(int i=0 ; i<max1 ; i++)
	{
		par[i]=i;
		size[i]=1;
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
 
ll kruskal(vector<edge> elist, vector<ll> &clist)
{
	sort(elist.begin(), elist.end(),comp);
	ll cost=0;
	for(auto i:elist)
	{
		if(root(i.a)!=root(i.b))
		{
			//add edges only which doesn't form loop;
			unionab(i.a,i.b);
			clist.pb(i.wt);
			cost+=i.wt;
		}
	}
	return cost;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    
 
    initialize();
 
    int n,m;
    ll k;
    cin>>n>>m>>k;
    vector<edge> elist;
    vll clist;
    for(ll i=0 ; i<m ; i++)
    {
    	int a,b,c;
    	cin>>a>>b>>c;
    	elist.pb({a,b,c});
    }	
 
	ll totalCost=kruskal(elist,clist);
	
	if(totalCost<=k)
		cout<<0;
	else if(clist.size()>k || clist.size()!=n-1)
		cout<<-1;
	else
	{
		int cnt=0;
		reverse(clist.begin(), clist.end());
 
		for(auto i:clist)
		{
			ll cost=i;
			totalCost-=cost;
			totalCost++;
			cnt++;
			if(totalCost<=k)
				break;
		}
		cout<<cnt<<endl;
	}
 
	return 0;
	//Always comment out input.txt and output.txt
}