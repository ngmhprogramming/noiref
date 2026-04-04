class SuffixArray {
private:
    string text;
    int n;

    // Sorting helper
    void sort_by_second_half(vector<int>& sa, const vector<int>& rank,
                             int h, int classes, vector<int>& cnt) {
        vector<int> pn(n);
        for (int i = 0; i < n; i++) {
            pn[i] = (sa[i] - h + n) % n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++) cnt[rank[pn[i]]]++;
        for (int i = 1; i < classes; i++) cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--) sa[--cnt[rank[pn[i]]]] = pn[i];
    }

    // Build suffix array
    void construct_sa() {
        const int alphabet_size = 256;
        vector<int> cnt(max(alphabet_size, n), 0);
        suffix_array.resize(n);
        rank_array.resize(n);

        for (int i = 0; i < n; i++) cnt[(unsigned char)text[i]]++;
        for (int i = 1; i < alphabet_size; i++) cnt[i] += cnt[i-1];
        for (int i = 0; i < n; i++) {
            suffix_array[--cnt[(unsigned char)text[i]]] = i;
        }
        
        rank_array[suffix_array[0]] = 0;
        int classes = 1;
        for (int i = 1; i < n; i++) {
            if (text[suffix_array[i]] != text[suffix_array[i-1]]) classes++;
            rank_array[suffix_array[i]] = classes - 1;
        }

        vector<int> next_rank(n);
        for (int h = 1; h < n; h <<= 1) {
            sort_by_second_half(suffix_array, rank_array, h, classes, cnt);
            
            next_rank[suffix_array[0]] = 0;
            classes = 1;
            for (int i = 1; i < n; i++) {
                pair<int, int> current = {
                    rank_array[suffix_array[i]],
                    rank_array[(suffix_array[i] + h) % n]
                };
                pair<int, int> previous = {
                    rank_array[suffix_array[i-1]],
                    rank_array[(suffix_array[i-1] + h) % n]
                };
                if (current != previous) classes++;
                next_rank[suffix_array[i]] = classes - 1;
            }
            rank_array = next_rank;
            if (classes == n) break; 
        }
    }

    void construct_lcp() {
        vector<int> inverse_sa(n);
        for (int i = 0; i < n; i++) inverse_sa[suffix_array[i]] = i;
        
        int match_len = 0;
        lcp_array.assign(n, 0);
        for (int i = 0; i < n; i++) {
            if (inverse_sa[i] == n - 1) {
                match_len = 0;
                continue;
            }
            int next_suffix_idx = suffix_array[inverse_sa[i] + 1];
            while (i + match_len < n && next_suffix_idx + match_len < n && 
                   text[i + match_len] == text[next_suffix_idx + match_len]) {
                match_len++;
            }
            lcp_array[inverse_sa[i]] = match_len;
            if (match_len > 0) match_len--;
        }
    }

public:
    vector<int> suffix_array;
    vector<int> lcp_array;
    vector<int> rank_array;

    SuffixArray(string input_text, bool add_terminal = true) {
        text = input_text;
        if (add_terminal) text += "$"; 
        n = text.size();
        construct_sa();
        construct_lcp();
    }

    // LCS of 2 strings, build with S + # + T
    // {s start, s end, t start, t end}
    vector<int> find_lcs(int split_point) {
        int max_len = 0;
        vector<int> res = {0, 0, 0, 0};
        
        for (int i = 0; i < n - 1; i++) {
            int p1 = suffix_array[i];
            int p2 = suffix_array[i+1];
            
            if ((p1 < split_point) != (p2 < split_point)) {
                if (p1 == split_point || p2 == split_point) continue;
                
                if (lcp_array[i] > max_len) {
                    max_len = lcp_array[i];
                    int start_s = (p1 < split_point) ? p1 : p2;
                    int start_t = (p1 < split_point) ? p2 : p1;
                    
                    int c_coord = start_t - (split_point + 1);
                    res = {start_s, start_s + max_len,
                           c_coord, c_coord + max_len};
                }
            }
        }
        return res;
    }

    // Binary search for pattern in string
    pair<int, int> find_pattern_range(const string& pattern) {
        int m = pattern.size();
        int first = -1, low = 0, high = n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (text.substr(suffix_array[mid], m) >= pattern) {
                first = mid;
                high = mid - 1;
            } else low = mid + 1;
        }
        if (first == -1 || text.substr(suffix_array[first], m) != pattern) {
            return {-1, -1};
        }

        int last = -1;
        low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (text.substr(suffix_array[mid], m) <= pattern) {
                last = mid;
                low = mid + 1;
            } else high = mid - 1;
        }
        return {first, last};
    }

    // Count distinct substrings
    long long count_distinct_substrings() {
        long long len = n - 1; 
        long long total_substrings = len * (len + 1) / 2;
        long long duplicated_substrings = 0;
        for (int lcp_val : lcp_array) {
            duplicated_substrings += lcp_val;
        }      
        return total_substrings - duplicated_substrings;
    }
};

// Suffix Array
string s = "banana";
SuffixArray sa(s);
sa.suffix_array[i];
sa.lcp_array[i];

// Distinct Substrings
sa.count_distinct_substrings() << endl;

// Pattern Matching
string pattern = "ana";
pair<int, int> range = sa.find_pattern_range(pattern);
// Occurrences: [range.first, range.second]

// Longest Common Substring
string s1 = "apple pie";
string s2 = "the apple falls";
int split_point = s1.size();
SuffixArray sa_lcs(s1 + "#" + s2);
sa_lcs.find_lcs(split_point);

// Smallest Cyclic Shift
// Build without $
sa.suffix_array[0];

// Glossary
// sa[i] = j
// starting index j in original string of ith lexographically smallest suffix



// lcp[i] = k, longest common prefix between sa[i] and sa[i-1]
// lcp[0] = 0

// rank[j] = i
// lexographical rank i of suffix starting at j
// inverse of the sa, sa[i] = j <=> rank[j] = i.