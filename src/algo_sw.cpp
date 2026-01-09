// Example: Count number of subarrays with sum at least k
// All numbers are non-negative
int s = 0, sum = 0, ans = 0;
for (int i = 0; i < n; i++) {
	sum += a[i];
	while (sum >= k) {
		ans += (n-i);
		sum -= a[s];
		s++;
	}
}