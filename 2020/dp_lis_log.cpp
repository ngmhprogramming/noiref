for(int i = 0; i < n; i++){
    int p = lower_bound(dp, dp+l, a[i])-dp;
    dp[p] = a[i];
    l = max(p+1, l);
}
