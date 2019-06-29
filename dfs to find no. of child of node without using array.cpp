ll dfs(ll s)
{
	ll cnt=0;
	vis[s]=true;
	for(auto node:adj[s])
	{
		if(!vis[node])
		{
			cnt+=dfs(node);
		}
	}
	cout<<s<<' '<<cnt<<endl;
	return cnt;
}