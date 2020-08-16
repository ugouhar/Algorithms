const ll N = 100;
vll adj[N];
ll par[N];
bool vis[N];
bool cycle = false;

void dfs(int s, int p) {
    color[s] = 1;
    for(auto i : adj[s]) {
        if(color[i] == 1) {
            cycle = true;
        }
        if(color[i] == 0) {
            dfs(i, s);
        }
    }
    color[s] = 2;
}

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