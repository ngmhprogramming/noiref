int gcd(int a, int b) {
	if (a > b) swap(a, b);
	while (a != 0) {
		b %= a;
		swap(a, b);
	}
	return b;
}