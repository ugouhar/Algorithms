const ll N = MAX5;
vector<pll> adj[N]; //{cost, node}
bool vis[N];
ll dist[N], par[N];
set<pll> pq;

void init(ll n){
  for(ll i=0 ; i<=n ; i++){
    adj[i].clear();
    vis[i] = false;
    dist[i]=inf;
    par[i] = i; 
  }
  pq.clear();
}

void relax(ll curr){
  if(vis[curr])
      return;

  vis[curr]=true;

  for(auto i:adj[curr]) {
    if(vis[i.second])
      continue;

    if(dist[curr]+i.first < dist[i.second]){
      dist[i.second] = dist[curr]+i.first;
      par[i.second] = curr; // to store path
      pq.insert({dist[i.second],i.second});
    }
  } 
}

void dijkstra(ll src){
  dist[src]=0;
  pq.insert({0,src});

  while(!pq.empty()){
    ll curr=(*pq.begin()).second;
    pq.erase(pq.begin());
    relax(curr);  
  }
}
