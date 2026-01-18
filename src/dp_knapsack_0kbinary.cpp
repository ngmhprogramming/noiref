for(int i = 0; i < n; i++){
	cin >> v >> w >> k;
	k = min(k, s/w);
	c = 1;
	while (k) {
		int ck = min(c, k);
		items.push_back({ v*ck, w*ck });
		k -= ck;
		c <<= 1;
	}
}

// apply normal knapsack