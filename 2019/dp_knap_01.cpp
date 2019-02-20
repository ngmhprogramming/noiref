for(int i = 0; i < n; i++){
    for(int j = s; j >= w[i]; j--){
        dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
    }
}
