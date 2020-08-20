void merge(ll a[], ll s, ll m, ll e) {
    ll n = e - s + 1;
    ll arr[n];
    ll p = s, q = m + 1, k = 0;
    for(ll i = s ; i <= e ; i++) {
        if(p > m) {
            arr[k++] = a[q++];
        } else if(q > e) {
            arr[k++] = a[p++];
        } else {
            if(a[p] < a[q]) {
                arr[k++] = a[p++];
            } else {
                arr[k++] = a[q++];
            }
        }
    }
    for(ll i = 0 ; i < n ; i++) {
        a[s++] = arr[i];
    }
}


void mergeSort(ll a[], ll s, ll e) {
    if(s >= e) {
        return;
    }
    ll m = (s + e) / 2;
    mergeSort(a, s, m);
    mergeSort(a, m + 1, e);
    merge(a, s, m, e);
}
