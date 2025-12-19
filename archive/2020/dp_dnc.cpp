long long cost(int s, int e){
    return (ps[e]-ps[s-1])*(e-s+1);
}
void dnc(int s, int e, long long x, int y, int k){
    if(s > e) return;
    int m = (s+e)/2, best = 0;
    dp[m][k] = LLONG_MAX/2;
    for(int i = x; (i <= y && i <= m); i++){
        if(dp[m][k] > dp[i][!k]+cost(i+1, m)){
            dp[m][k] = dp[i][!k]+cost(i+1, m);
            best = i;
        }
    }
    if(s < m) dnc(s, m-1, x, best, k);
    if(m < e) dnc(m+1, e, best, y, k);
}
for(int i = 1; i <= n; i++) dp[i][0] = LLONG_MAX/2;
for(int i = 1; i <= g; i++){
    for(int j = 1; j <= n; j++) dp[j][i%2] = LLONG_MAX/2;
    dnc(0, n, 0, n, i%2);
}
