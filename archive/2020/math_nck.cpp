//Naive
if(k > n-k) k = n-k;
for(int i = 0; i < k; i++){
    ans *= (n-i);
    ans /= (i+1);
}

//Precomputed
//fac -> factorial
//mi -> modular inverse
ll nck(ll n, ll k){
	if(n < k) return 0;
	return (((fac[n]*mi[k])%MOD)*mi[n-k])%MOD;
}