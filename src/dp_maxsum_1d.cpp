int ans = nums[0], cur = nums[0];
for (int i = 1; i < nums.size(); i++) {
	if (cur < 0) cur = 0;
	cur += nums[i];
	ans = max(ans, cur);
}