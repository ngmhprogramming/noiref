int mis(int v, bool take, int p){
    if(dp[v][take] != -1) return dp[v][take];
    int ans = take*c[v];
    for(auto it:adj[v]){
        if(it == p) continue;
        int temp = mis(it, 0, v);
        if(!take) temp = max(temp, mis(it, 1, v));
        ans += temp;
    }
    return dp[v][take] = ans;
}
void ans(int v, bool take, int p){
    for(auto it:adj[v]){
        if(it == p) continue;
        int temp0 = dp[it][0], temp1 = (take ? -1 : dp[it][1]);
        if(temp0 > temp1) ans(it, 0, v);
        else { a.push_back(it); ans(it, 1, v); }
    }
}
mis(0, 0, -1);
mis(0, 1, -1);
if(dp[0][1] > dp[0][0]){ a.push_back(0); ans(0, 1, -1); }
else ans(0, 0, -1);
