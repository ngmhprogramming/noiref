int full = (1 << n) - 1;
for (int mask = 0; mask <= full; mask++) {
	for (int i = 0; i < n; i++) {
		dp[mask][i] = INF;
	}
}
dp[1][0] = 0; // assume source is node 0
for (int mask = 1; mask <= full; mask++) {
	for (int i = 0; i < n; i++) {
		if (!(mask & (1 << i)) || dp[mask][i] >= INF) continue;
		for (int j = 0; j < n; j++) {
			if (mask & (1 << j)) continue;
			if (adj[i][j] >= INF) continue;
			int newMask = mask | (1 << j);
			dp[newMask][j] = min(dp[newMask][j], dp[mask][i] + adj[i][j]);
		}
	}
}
ll ans = INF;
for (int i = 0; i < n; i++) {
	if (adj[i][0] < INF) {
		// close the tour
		ans = min(ans, dp[full][i] + adj[i][0]);
	}
}