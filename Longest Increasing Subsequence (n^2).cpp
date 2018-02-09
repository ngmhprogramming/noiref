int nums[n], lis[n], ans;
for(int i = 0; i < n; i++){
  lis[i] = 1;
  for(int j = 0; j < i; j++){
    if(nums[j] < nums[i]){
      lis[i] = max(lis[i], lis[j] + 1);
    }
  }
  ans = max(ans, lis[i]);
}
//QUERY: ans
