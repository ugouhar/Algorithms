#include<bits/stdc++.h>
#define ll long long int
#define MAX5 100005
using namespace std;

ll BIT[MAX5];
ll pref[MAX5];

void constructBIT(ll a[], ll n) {
    pref[0] = 0;
    for(ll i = 1 ; i <= n ; i++) {
        BIT[i] = 0;
        pref[i] = pref[i - 1] + a[i];
    }
    for(ll i = 1 ; i <= n ; i++) {
        ll par_i = i - (i & (-i));
        BIT[i] = pref[i] - pref[par_i];
    }
}

ll getSum(ll idx) {
    ll sum = 0;
    while(idx > 0) {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }
    return sum;
}

ll query(ll l, ll r) {
    return getSum(r) - getSum(l - 1);
}

void update(ll n, ll idx, ll val) {
    while(idx <= n) {
        BIT[idx] += val;
        idx += idx & (-idx);
    }
}



int main() {
    freopen("input.txt", "r", stdin);

    ll n;
    cin >> n;
    ll arr[n + 1];
    for(ll i = 1 ; i <= n ; i++) {
        cin >> arr[i];
    }
    constructBIT(arr, n);

    return 0;
}