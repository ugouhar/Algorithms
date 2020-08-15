const ll N = 1000;
ll par[N], sz[N];
void init() {
    for(ll i = 0 ; i < N ; i++) {
        par[i] = i;
        sz[i] = 1;
    }
}
ll root(ll x) {
    return (x == par[x] ? x : (par[x] = root(par[x])));
}
void unionab(ll a, ll b) {
    ll ra = root(a), rb = root(b);
    if(ra == rb)return;
    if(sz[ra] > sz[rb])swap(ra, rb);
    
    par[ra] = par[rb];
    sz[rb] += sz[ra];
}
