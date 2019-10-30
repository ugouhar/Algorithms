/*
Given an array  of size  and some queries. There are two types of queries:

Update: Given  idx and val, update array element A[idx] as A[idx] = val.
Query: Given l and r return the value of min(A[l], A[l+1],...,A[r-1], A[r]) such that
	   0<=l<=r<N. 

*/

#include<bits/stdc++.h>
#define ll long long int
#define MAX 100
#define inf 1000000000000000000
using namespace std;

ll A[MAX];
ll tree[4*MAX];
void build(ll node,ll start,ll end)
{
	if(start==end)
	{
		tree[node] = A[start];
	}
	else
	{
		ll mid = (start + end)/2;
		build(2*node, start, mid);
		build(2*node+1, mid+1, end);
		tree[node] = min(tree[2*node], tree[2*node+1]);

	}
}

void update(ll node, ll start, ll end, ll idx, ll val)
{
	if(start==end)
	{
		A[idx] = val;
		tree[node] = val;	
	}
	else
	{
		ll mid = (start+end)/2;
		if(idx>=start && idx<=mid)
		{
			update(2*node, start, mid, idx, val);
		}
		else
		{
			update(2*node+1, mid+1, end, idx, val);
		}
		tree[node] = min(tree[2*node], tree[2*node+1]);
	}	
}


ll query(ll node, ll start, ll end, ll l, ll r)
{
	if(r<start || l>end)
	{
		return inf;
	}
	else if(l<=start && r>=end)
	{
		return tree[node];
	}
	else
	{
		ll mid = (start+end)/2;
		ll lq = query(2*node, start, mid, l, r);
		ll rq = query(2*node+1, mid+1, end, l, r);
		return min(lq,rq);
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	ll n, q;
	cin>>n>>q;
	ll node=1, start = 1, end = n;
	for(ll i=1 ; i<=n ; i++)
	{
		cin>>A[i];
	}
	
	build(node,start,end);


	
	while(q--)
	{
	    char c;
	    cin>>c;
	    if(c=='q')
	    {
	        ll l,r;
	        cin>>l>>r;
	        ll ans = query(node, start, end, l, r);
	        cout<<ans<<endl;
	    }
	    else
	    {
	        ll x,y;
	        cin>>x>>y;
	        update(node, start, end, x, y);
	    }
	}
	


	
	return 0;
}
