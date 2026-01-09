// Example: Bobek
// Count number of subsets with sum <= tgt
left = n/2; right = n-left;
vector<int> sums;
for (int i = 0; i < (1 << left); i++) {
	int cur = 0;
	for (int j = 0; j < left; j++) {
		if (i & (1 << j)) cur += a[j];
	}
	sums.push_back(cur);
}
sort(sums.begin(), sums.end());
for (int i = 0; i < (1 << right); i++) {
	int cur = 0;
	for (int j = 0; j < right; j++) {
		if (i & (1 << j)) cur += a[left + j];
	}
	ans += upper_bound(sums.begin(), sums.end(), tgt-cur) - sums.begin();
}