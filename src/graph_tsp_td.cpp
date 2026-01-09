ll adj[MAXN][MAXN], dp[1 << MAXN][MAXN];

ll tsp(int mask, int pos) {
	if (mask == (1 << n) - 1) {
		// assume node 0 is the start and end
		return adj[pos][0] < INF ? adj[pos][0] : INF;
	}
	if (dp[mask][pos] != -1) return dp[mask][pos];
	ll ans = INF;
	for (int i = 0; i < n; i++) {
		if ((mask & (1 << i)) == 0 && adj[pos][i] < INF) {
			ans = min(ans, adj[pos][i] + tsp(mask | (1 << i), i));
		}
	}
	return dp[mask][pos] = ans;
}

memset(dp, -1, sizeof(dp));
ll res = tsp(1, 0); // initial mask has source visited