int dp[MAXN][MAXM];
int lcs(int i, int j) {
	if (i == 0 || j == 0) return 0;
	if (dp[i][j] != -1) return dp[i][j];
	dp[i][j] = max(lcs(i-1, j), lcs(i, j-1));
	if (a[i-1] == b[j-1]) dp[i][j] = max(dp[i][j], lcs(i-1, j-1) + 1);
	return dp[i][j];
}

memset(dp, -1, sizeof(dp));