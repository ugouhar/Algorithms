const ll N = MAX5;
vector<pll> adj[N]; //{cost, node}
bool vis[N];
ll dist[N], par[N];
priority_queue<pll, vector<pll>, greater<pll>> pq;

void init(ll n){
  for(ll i=0 ; i<=n ; i++){
    adj[i].clear();
    vis[i] = false;
    dist[i]=inf;
    par[i] = i; //to store path
  }
  while(!pq.empty())
    pq.pop();
}

void relax(ll curr){
  if(vis[curr])
      return;

  vis[curr]=true;

  for(auto i:adj[curr]) {
    if(!vis[i.second]){
      if(dist[curr]+i.first < dist[i.second]){
        dist[i.second] = dist[curr]+i.first;
        // par[i.second] = curr;
        pq.push({dist[i.second],i.second});
      }
    }
  } 
}

void dijkstra(ll src){
  dist[src]=0;
  pq.push({0,src});

  while(!pq.empty()){
    ll curr=pq.top().second;
    pq.pop();
    relax(curr);  
  }
}

