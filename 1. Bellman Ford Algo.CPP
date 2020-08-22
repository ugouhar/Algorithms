const ll inf = 1e9;
const ll N = 1003;
struct edge{
  ll from, to;
  ll wt;
};
ll dist[N];

void init(){
  for(ll i=0 ; i<N ; i++){
    dist[i] = inf;
  }
}

void relax(edge e){
  if(dist[e.from]==inf)
    return;
  if(dist[e.from] + e.wt < dist[e.to]){
    dist[e.to] = dist[e.from] + e.wt; 
  }
}

bool bellmanFord(ll n, vector<edge> elist){
  init();
  dist[0]=0;
  for(ll i=0 ; i<n-1 ; i++){
    for(auto j : elist){
      relax(j);
    }
  }
}