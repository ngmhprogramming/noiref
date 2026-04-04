struct Manacher {
    vector<int> p;
    string t;

    Manacher(string s) {
		// Insert # around each character
        t = "#";
        for (char c : s) {
            t += c;
            t += "#";
        }
		// Manacher's
        int n = t.size();
        p.assign(n, 0);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r) ? 1 : min(p[l + r - i], r - i + 1);
            while (0 <= i - k && i + k < n && t[i - k] == t[i + k]) {
                k++;
            }
            p[i] = k--;
            if (i + k > r) {
                l = i - k;
                r = i + k;
            }
        }
    }

	// Get longest palindrome: {index, length}
    pair<int, int> get_longest() {
        int max_len = 0, center = 0;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] - 1 > max_len) {
                max_len = p[i] - 1;
                center = i;
            }
        }
        return {(center - max_len) / 2, max_len};
    }

	// Check if substring is palindrome
    bool is_palindrome(int i, int j) {
        int len = j - i + 1;
        int center_in_t = i + j + 1;
        return p[center_in_t] - 1 >= len;
    }

	// Length of longest palindrome centered at index
	// even_center = true means the palindrome is BETWEEN i and i+1
    int get_length_at(int i, bool even_center = false) {
        int center_in_t = even_center ? (2 * i + 2) : (2 * i + 1);
        return p[center_in_t] - 1;
    }
};