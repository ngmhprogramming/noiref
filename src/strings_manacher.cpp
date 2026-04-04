// for odd length palindromes, returns radius of palindrome at each index
vector<int> manacher(const string &s) {
	int n = s.size();
	vector<int> p(n);
	int l = 0, r = -1;
	for (int i = 0; i < n; i++) {
		int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);
		while (0 <= i - k && i + k < n && s[i - k] == s[i + k]) {
			k++;
		}
		p[i] = k;
		if (i + k - 1 > r) {
			l = i - k + 1;
			r = i + k - 1;
		}
	}
	return p;
}
// surround with #s so we only have to run odd case
string s, t;
for (char c : s) {
	t.push_back('#');
	t.push_back(c);
}
t.push_back('#');
vector<int> p = manacher(t);
// handle # removal accordingly