const ll N = 100;
vll adj[N];
bool vis[N];
bool cycle = false;
ll par[N];

void init() {
    for(ll i = 0 ; i < N ; i++) {
        adj[i].clear();
        vis[i] = false;
        par[i] = i;
    }
    cycle = false;
}

void detectCycle(ll s) {
    vis[s] = true;
    for(auto i : adj[s]) {
        if(!vis[i]) {
            par[i] = s;
            detectCycle(i);
        } else if(par[s] != i) {
            cycle = true;
        }
    }
}

bool isCyclic(ll n) {
    init();
    for(ll i = 0 ; i < n ; i++) {
        if(!vis[i]) {
            detectCycle(i);
        }
    }
    return cycle;
}
