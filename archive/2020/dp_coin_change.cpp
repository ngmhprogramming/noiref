dp[0] = 0;
for(int i = 1; i <= v; i++){
    dp[i] = INT_MAX;
    for(int j = 0; j < n; j++){
        if(i >= c[j]) dp[i] = min(dp[i], dp[i-c[j]]+1);
    }
}
