int len = 0, dp[n];
memset(dp, 0, sizeof(dp));
for (int x : a) {
	int pos = lower_bound(dp, dp + len, x) - dp;
	dp[pos] = x;
	if (pos == len) len++;
}
cout << len;