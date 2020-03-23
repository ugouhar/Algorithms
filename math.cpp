/*
Math utility functions
*/

/////////////////////// Method 1 ///////////////////////////////////////

ll gcd, x, y;
void extendedEuclid(ll A, ll B){
	if(B==0){
		gcd=A;
		x=1;
		y=0;
	}
	else{
		extendedEuclid(B,A%B);	//GCD(A,B) = GCD(B, A%B);
		ll temp=x;
		x=y;
		y=temp-(A/B)*y;
	}
}


////////////////////////////////////////////////////////////////////////


ll modInv(ll A,ll M){   // To find multiplicative inverse of 
                        // A under modulo M.
	extendedEuclid(A,M);
	return (x%M + M)%M;
}


////////////////////////////////////////////////////////////////////////



ll fact[100], ifact[100], inv[100];	//factorial and inverse factorial

void invFact(ll M){

    ifact[0] = 1;
    ifact[1] = 1;
    for(ll i=0 ; i<100 ; i++){
        inv[i] = (inv[M%i] * (M - M/i)) % M;
    }

    for(ll i=2 ; i<100 ; i++){
        ifact[i] = (ifact[i-1] * inv[i]) % M;
    }
}

void fact_ifact(ll m){
	fact[0]=1;
	ifact[0]=1;
	for(ll i=1 ; i<100 ; i++){
		fact[i]=(i%m * fact[i-1])%m;
		ifact[i]=(modInv(i,m)*ifact[i-1])%m;
	}
}


////////////////////////////////////////////////////////////////////////

ll nCr(ll n,ll r,ll m){
	ll a = fact[n];
	ll b = ifact[r];
	ll c = ifact[n-r];
	ll d = (b*c)%m;
	return (a*d)%m;
}


//////////////////////////METHOD2///////////////////////////////////////

void inverse2(ll M){
    inv2[0]=inv2[1]=1;

    for(ll i=2 ; i<100 ; i++){
        inv2[i] = (inv2[M%i] * (M - M/i)) % M;
    }
}

void inverse3(ll M){
    inv2[0]=inv2[1]=1;

    for(ll i=2 ; i<100 ; i++){
        inv2[i] = modExp(i, M-2, M);
    }
}

void invFact2(ll M){

    ifact2[0] = 1;
    ifact2[1] = 1;
    
    for(ll i=2 ; i<100 ; i++){
        ifact2[i] = (ifact2[i-1] * inv2[i]) % M;
    }
}





////////////////////////////////////////////////////////////////////////


ll modExp(ll x,ll n,ll M){
    if(n==0)
        return 1;
    else if(n%2 == 0)        //n is even
        return modExp((x*x)%M,n/2,M);
    else                     //n is odd
        return (x*modExp((x*x)%M,(n-1)/2,M))%M;

}


////////////////////////////////////////////////////////////////////////


bool checkPrime(ll n) {
    for (ll i=2 ; i*i<=n ; i++) {
        if (n%i==0) {
            return false;
        }
    }
    return true;
}



////////////////////////////////////////////////////////////////////////

void sieve(ll N) {
        bool isPrime[N+1];
        for(ll i=0 ; i<=N ; i++) {
            isPrime[i]=true;
        }
        isPrime[0]=false;
        isPrime[1]=false;

        for(ll i=2 ; i*i<=N ; i++) {
             if(isPrime[i]==true){ 
                //Mark all the multiples of i as composite numbers
                 for(ll j=i*i ; j<=N ; j+=i)
                     isPrime[j] = false;
             }
        }

        vll vprime;
        for(ll i=2 ; i<=N ; i++){
        	if(isPrime[i])
        		vprime.pb(i);
        }
}


////////////////////////////////////////////////////////////////////////


ll PHI(ll n) {
    ll result = n;
    for(ll i=2 ; i*i<=n ; i++){
        if(n%i == 0) {
            ll cnt=0;
            while(n%i == 0){
                n /= i;
                cnt++;
            }
            result -= result/i;
        }
    }
    if(n > 1)
        result -= result/n;

    return result;
}


////////////////////////////////////////////////////////////////////////


ll phi[MAX6];

void computePhi(){
    for(ll i=1 ; i<MAX6 ; i++){
        phi[i] = i;
    }
    for(ll i=2 ; i<MAX6 ; i++){
        if(phi[i] == i){
            phi[i] = i-1;
            for(ll j=2*i ; j<=MAX6 ; j+=i){
                phi[j] = (phi[j]/i)*(i-1);
            }
        }
    }
}


////////////////////////////////////////////////////////////////////////