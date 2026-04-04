class StringHash {
private:
    int n;
    const long long m1 = 1e9 + 7, m2 = 1e9 + 9;
    const long long p1 = 31, p2 = 37;
    vector<long long> h1, h2;
    vector<long long> pow1, pow2;

public:
    StringHash(string const& s) {
        n = s.size();
        h1.assign(n + 1, 0);
        h2.assign(n + 1, 0);
        pow1.assign(n + 1, 1);
        pow2.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] + (s[i] - 'a' + 1) * pow1[i]) % m1;
            h2[i + 1] = (h2[i] + (s[i] - 'a' + 1) * pow2[i]) % m2;
            pow1[i + 1] = (pow1[i] * p1) % m1;
            pow2[i + 1] = (pow2[i] * p2) % m2;
        }
    }

	// Get double hash of substring
    pair<long long, long long> get_hash(int i, int j) {
        long long res1 = (h1[j + 1] - h1[i] + m1) % m1;
        long long res2 = (h2[j + 1] - h2[i] + m2) % m2;
        return {res1, res2};
    }

	// Check equality of substrings
    bool compare_substrings(int i1, int i2, int len) {
        auto hash1 = get_hash(i1, i1 + len - 1);
        auto hash2 = get_hash(i2, i2 + len - 1);
        if (i1 < i2) {
            hash1.first = (hash1.first * pow1[i2 - i1]) % m1;
            hash1.second = (hash1.second * pow2[i2 - i1]) % m2;
        } else {
            hash2.first = (hash2.first * pow1[i1 - i2]) % m1;
            hash2.second = (hash2.second * pow2[i1 - i2]) % m2;
        }
        return hash1 == hash2;
    }

	// Find all occurrences of pattern in text
    static vector<int> find_occurrences(string text, string pattern) {
        int n = text.size(), m = pattern.size();
        if (m > n) return {};
        
        StringHash th(text);
        
		// Find pattern hash
        long long ph1 = 0, ph2 = 0;
        long long p1 = 31, p2 = 37, m1 = 1e9 + 7, m2 = 1e9 + 9;
        vector<long long> p_pow1(m), p_pow2(m);
        p_pow1[0] = 1; p_pow2[0] = 1;

        for(int i=0; i<m; i++) {
            ph1 = (ph1 + (pattern[i] - 'a' + 1) * p_pow1[i]) % m1;
            ph2 = (ph2 + (pattern[i] - 'a' + 1) * p_pow2[i]) % m2;
            if(i + 1 < m) {
                p_pow1[i+1] = (p_pow1[i] * p1) % m1;
                p_pow2[i+1] = (p_pow2[i] * p2) % m2;
            }
        }

        vector<int> found;
        for (int i = 0; i <= n - m; i++) {
            auto thash = th.get_hash(i, i + m - 1);
            if (thash.first == (ph1 * th.get_pow1(i)) % m1 && 
                thash.second == (ph2 * th.get_pow2(i)) % m2) {
                found.push_back(i);
            }
        }
        return found;
    }

    long long get_pow1(int i) { return pow1[i]; }
    long long get_pow2(int i) { return pow2[i]; }
};