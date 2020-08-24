/*
Given an array  of size  and some queries. There are two types of queries:

Update: Given  and , update array element A[idx] as A[idx] = A[idx]+val.
Query: Given l and r return the value of A[l]+A[l+1]+...+A[r-1]+A[r] such that
	   0<=l<=r<N. 

*/

const ll N = 100;
ll A[N];
ll tree[4 * N];
void build(ll node, ll start, ll end) {
  if (start == end) {
    tree[node] = A[start];
  } else {
    ll mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
  }
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

int main() {
  ll n;
  cin >> n;
  ll node = 1, start = 0, end = n - 1;
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  build(node, start, end);
  ll ans = query(node, start, end, 2, 3);
  cout << ans << endl;

  return 0;
}