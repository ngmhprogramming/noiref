class ZAlgorithm {
private:
    string s;
    int n;

public:
    vector<int> z;
	// Build array
	// z[i] is longest string that is
	// prefix of s and prefix of suffix of s starting at i
    ZAlgorithm(string input_s) : s(input_s), n(input_s.size()) {
        z.assign(n, 0);
        int l = 0, r = 0;
        for (int i = 1; i < n; i++) {
            if (i < r) {
                z[i] = min(r - i, z[i - l]);
            }
            while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
                z[i]++;
            }
            if (i + z[i] > r) {
                l = i;
                r = i + z[i];
            }
        }
        z[0] = n;
    }

	// Find starting indices of a pattern in a text
    static vector<int> find_pattern(const string& text, const string& pattern) {
        string concat = pattern + "\1" + text;
        ZAlgorithm za(concat);
        vector<int> occurrences;
        int m = pattern.size();
        for (int i = m + 1; i < (int)za.z.size(); i++) {
            if (za.z[i] == m) {
                occurrences.push_back(i - m - 1);
            }
        }
        return occurrences;
    }

	// Length of period
    int get_shortest_period() {
        for (int i = 1; i < n; i++) {
            if (n % i == 0 && i + z[i] == n) {
                return i;
            }
        }
        return n;
    }

	// Count how many suffixes match prefix of length
    int count_prefix_occurrences(int len) {
        int count = 0;
        for (int val : z) {
            if (val >= len) count++;
        }
        return count;
    }

	// Check if Suffix matches Prefix at index i
    bool is_border(int i) {
        return i + z[i] == n;
    }
};