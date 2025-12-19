long long adj[14][14], dp[8200][14];

//start with 1, 0
//mask is 0 visited, at node 0
long long tsp(long long mask, long long pos){
	if(mask == visited) return adj[pos][0];
	if(dp[mask][pos] != -1) return dp[mask][pos];
	long long ans = LLONG_MAX;
	for(int i = 0; i < m; i++){
		if((mask&(1<<i)) == 0){
			long long newans = adj[pos][i]+tsp(mask|(1<<i), i);
			ans = min(ans, newans);
		}
	}
	return dp[mask][pos] = ans;
}


visited = (1 << m)-1;
res = tsp(1, 0);
if(res < 0) cout << "-1";
else cout << res;
