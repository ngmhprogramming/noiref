// Stolen from DNC code
// Use i%2 and !(i%2) for indexing
for (int i = 1; i <= g; i++) {
    for (int j = 1; j <= n; j++) dp[j][i%2] = INF;
    dnc(0, n, 0, n, i%2);
}