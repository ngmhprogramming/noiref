int ans = 0, dp[n];
memset(dp, 0, sizeof(dp));
for (int i = 0; i < n; i++) {
	for (int j = 0; j < i; j++) {
		if (a[j] < a[i]) {
			dp[i] = max(dp[i], dp[j]);
		}
	}
	dp[i]++;
	ans = max(ans, dp[i]);
}