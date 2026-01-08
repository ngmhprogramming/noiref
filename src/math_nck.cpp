ll fac[MAXN+1], modinv[MAXN+1];

ll nck(ll n, ll k) {
	if (n < k) return 0;
	ll res = fac[n];
	res = (res * modinv[k]) % MOD;
	res = (res * modinv[n-k]) % MOD;
	return res;
}

fac[0] = 1;
for(int i = 1; i <= MAXN; i++) {
	fac[i] = fac[i-1] * i % MOD;
}
modinv[MAXN] = powmod(fac[MAXN], MOD-2, MOD);
for(int i = MAXN; i > 0; i--) {
	modinv[i-1] = modinv[i] * i % MOD;
}