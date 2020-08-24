ll merge(ll a[], ll s, ll m, ll e) {
  ll cnt = 0;
  ll n = e - s + 1;
  ll arr[n];
  ll p = s, q = m + 1, k = 0;
  for (ll i = s; i <= e; i++) {
    if (p > m) {
      arr[k++] = a[q++];
    } else if (q > e) {
      arr[k++] = a[p++];
    } else {
      if (a[p] <= a[q]) {
        arr[k++] = a[p++];
      } else {
        cnt += (m - p + 1);
        arr[k++] = a[q++];
      }
    }
  }
  for (ll i = 0; i < n; i++) {
    a[s++] = arr[i];
  }
  return cnt;
}

ll countInv(ll a[], ll s, ll e) {
  if (s >= e) {
    return 0;
  }
  ll m = (s + e) / 2;
  ll left = countInv(a, s, m);
  ll right = countInv(a, m + 1, e);
  return (left + merge(a, s, m, e) + right);
}