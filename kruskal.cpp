const ll N = 1000;
ll par[N], sz[N];
struct edge {
  int a, b;
  ll wt;
};

bool comp(edge n1, edge n2) {
  return n1.wt < n2.wt;
}

void init() {
  for (ll i = 0; i < N; i++) {
    par[i] = i;
    sz[i] = 1;
  }
}

ll root(ll x) {
  return (x == par[x] ? x : (par[x] = root(par[x])));
}

void unionab(ll a, ll b) {
  ll ra = root(a), rb = root(b);
  if (ra == rb) return;
  if (sz[ra] > sz[rb]) swap(ra, rb);

  par[ra] = par[rb];
  sz[rb] += sz[ra];
}

ll kruskal(vector < edge > elist) {
  initialize();
  sort(elist.begin(), elist.end(), comp);
  ll cost = 0;
  for (auto i: elist) {
    if (root(i.a) != root(i.b)) {
      //add edges only which doesn't form loop;
      unionab(i.a, i.b);
      cost += i.wt;
    }
  }
  return cost;
}