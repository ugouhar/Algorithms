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

Frequently used bitwise operation tricks for competitive programming -
Along with intuition of why the trick works.

1) Check if the number is odd
X & 1 = 1

(Works because only the last bit remains after operation)

2) Same logic be extended to check if the kth bit is set
(X >> k) & 1 = 1

3) Flip the kth bit
X = X ^ (1 << k)

4) Set and Unset Kth bit - Instead of XOR use OR/AND
X = X | (1 << k)
X = X & ~(1 << k)

5) Count set bits
Use __builtin_popcountll, very fast.

6) Check if the number is a power of 2
X & (X - 1) = 0
	
7) Super handy in solving problems many times
A + B = (A | B) + (A & B)
