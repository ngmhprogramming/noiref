int nums[n], dp[n], length;
for(int i = 0; i < n; i++){
  int p = lower_bound(dp, dp+length, nums[i])-dp;
  dp[p] = nums[i];
  length = max(p+1, length);
}
//QUERY: length
