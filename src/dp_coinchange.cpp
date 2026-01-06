const int INF = 1e9;
vector<int> dp(v + 1, INF);
dp[0] = 0;
for (int i = 1; i <= v; i++) {
	for (int j = 0; j < n; j++) {
		if (i >= c[j] && dp[i - c[j]] != INF) {
			dp[i] = min(dp[i], dp[i - c[j]] + 1);
		}
	}
}
cout << dp[v];