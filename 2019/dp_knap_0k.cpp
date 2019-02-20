//further speedup:
//take top s/w most valued items
//for every possible item
//not just multiple copies of one item

for(int i = 0; i < n; i++){
	cin >> v >> w >> k;
	k = min(k, s/w);
	c = 1;
	while(true){
		if(k < c) break;
		items.push_back(pi(v*c, w*c));
		k -= c;
		c *= 2;
	}
	if(k != 0) items.push_back(pi(v*k, w*k));
}
for(auto it :items){
	for(int i = s; i >= it.second; i--){
		dp[i] = max(dp[i], dp[i-it.second]+it.first);
	}
}
