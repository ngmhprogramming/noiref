long long derp(int idx, int prev, int same, int allzero){
	if(idx == num.size()) return dp[idx][prev][same][allzero] = !allzero;
	if(dp[idx][prev][same][allzero] != -1) return dp[idx][prev][same][allzero];
	long long sum = 0, limit;
	if((!allzero && same) || (allzero && idx == 0)) limit = num[idx];
	else limit = 9;
	for(int i = 0; i <= limit; i++){
		if(i == 4) continue;
		if(allzero){
			if(i == 0) sum += derp(idx+1, 10, 1, 1);
			else sum += derp(idx+1, i, (idx == 0 && i == limit), 0);
		} else if(!(i == 3 && prev == 1)){
			if(same && i == num[idx]) sum += derp(idx+1, i, 1, 0);
			else sum += derp(idx+1, i, 0, 0);
		}
	}
	return dp[idx][prev][same][allzero] = sum;
}
void dcmp(long long x){
	num.clear();
	while(x > 0){ num.push_back(x%10); x /= 10; }
	reverse(num.begin(), num.end());
}
long long solve(long long x){
	if(memo.count(x) != 0) return memo[x];
	memset(dp, -1, sizeof(dp));
	dcmp(x);
	return memo[x] = derp(0, 10, 1, 1);
}
