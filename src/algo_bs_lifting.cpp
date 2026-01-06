long long n; cin >> n;
long long cur = 0, gap = 1e6, next;
while (gap > 0) {
	while (next = cur + gap, next * next * next < n) {
		cur = next;
	}
	gap >>= 1;
}
cout << cur+1 << "\n";