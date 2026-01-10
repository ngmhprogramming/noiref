bitset<MAXX> dp;
dp[0] = 1;
for (int i = 0; i < n; i++) {
	dp |= dp << w[i];
}
cout << dp[x];