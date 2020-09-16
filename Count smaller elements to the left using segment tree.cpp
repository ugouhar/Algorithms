const ll N = 100005;
ll A[N];
ll tree[4 * N];

void build() {
  memset(tree, 0, sizeof(tree));
  memset(A, 0, sizeof(A));
}

void update(ll node, ll start, ll end, ll idx, ll val) {
  if (start == end) {
    A[idx] += val;
    tree[node] += val;
  } else {
    ll mid = (start + end) / 2;
    if (idx >= start && idx <= mid) {
      update(2 * node, start, mid, idx, val);
    } else {
      update(2 * node + 1, mid + 1, end, idx, val);
    }
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
}

ll query(ll node, ll start, ll end, ll l, ll r) {
  if (r < start || l > end) {
    return 0;
  } else if (l <= start && r >= end) {
    return tree[node];
  } else {
    ll mid = (start + end) / 2;
    ll lq = query(2 * node, start, mid, l, r);
    ll rq = query(2 * node + 1, mid + 1, end, l, r);
    return (lq + rq);
  }
}

void solve() {

  build();
  ll node = 1, start = 0, end = N - 1;

  int n;
  cin >> n;
  ll a[n], smLeft[n];
  // assuming all numbers belong to range [1, 10000] 
  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    a[i] = x;
    smLeft[i] = query(node, start, end, 0, x - 1);
    update(node, start, end, x, 1);
  }

  for (ll i = 0; i < n; i++) {
    cout << smLeft[i] << ' ';
  }
  cout << endl;

}