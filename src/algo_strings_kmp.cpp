// Returns prefix function
// p[i] is longest prefix of s[0..i] which is also a suffix of it

vector<int> kmp(string s) {
    int n = s.size();
    vector<int> p(n);
    for (int i = 1; i < n; i++) {
        int j = p[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
		}
        if (s[i] == s[j]) j++;
        p[i] = j;
    }
    return p;
}

// Example: Count how many times a pattern occurs in a text
string concat = pattern + '#' + text;
vector<int> p = kmp(concat);
int ans = 0;
for (int i = 0; i < pattern.size() + 1; i < p.size(); i++) {
	if (p[i] == pattern.size()) ans++;
}