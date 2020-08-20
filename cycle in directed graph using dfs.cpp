const ll N = 100;
vll adj[N];
ll color[N];
bool cycle = false;

void init() {
    for(ll i = 0 ; i < N ; i++) {
        adj[i].clear();
        color[i] = 0;
    }
    cycle = false;
}

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
