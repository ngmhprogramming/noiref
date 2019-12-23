int lcs(int al, int bl){
    if(al == 0 || bl == 0) return 0;
    if(dp[al][bl] != -1) return dp[al][bl];
    dp[al][bl] = max(lcs(al-1, bl), lcs(al, bl-1));
    if(a[al-1] == b[bl-1]) dp[al][bl] = max(dp[al][bl], lcs(al-1, bl-1)+1);
    return dp[al][bl];
}
