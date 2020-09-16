bool isSet(ll x, ll i){
	return ((x&(1LL<<i)) > 0);
}

void setBit(ll &x, ll i){
	x |= (1LL<<i);
}

void unsetBit(ll &x, ll i){
	x &= ~(1LL<<i);
}

void toggleBit(ll &x, ll i){
	x ^= (1LL<<i);
}