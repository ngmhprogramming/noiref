//Example - Candymountain
for(int i = 0; i < k; i++) s.insert(dp[i]);
for(int i = k; i < n; i++){
    dp[i] = max(dp[i], *s.begin());
    s.erase(s.find(dp[i-k]));
    s.insert(dp[i]);
}