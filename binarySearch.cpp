ll binary_search(ll a[], ll n, ll key) {
    ll low = i, high = n - 1;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(a[mid] < key) {
            low = mid + 1;
        } else if(a[mid] > key) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

ll my_lower_bound(ll a[], ll n, ll key) {
    ll low = 0, high = n - 1;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if(a[mid] < key) {
            low = mid + 1;
        } else if(a[mid] > key) {
            high = mid - 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}
ll my_upper_bound(ll a[], ll n, ll key) {
    ll low = 0, high = n - 1;
    while(low <= high) {
        ll mid = (low + high) / 2;
        if( a[mid] < key) {
            low = mid + 1;
        } else if(a[mid] > key) {
            high = mid - 1;
        }  else {
            low = mid + 1;
        }
    }
    return low;
}
