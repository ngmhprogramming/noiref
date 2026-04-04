// Compressed Version

class SuffixTree {
public:
    static const int INF = 1e9;
    
    struct Node {
        int l, r, p, s;
        int next[28]; // 26 letters + '{' (terminator) + '|' (extra separator)
        int leaf_count;
        int depth;

        Node(int _l = -1, int _r = -1, int _p = -1) 
            : l(_l), r(_r), p(_p), s(0), leaf_count(0), depth(0) {
            memset(next, -1, sizeof(next));
        }

        int len(int la) const {
            return min(r, la) - l + 1;
        }
    };

    vector<Node> tree;
    string a;
    int tv, tp, ts, la;

    SuffixTree(string _s) {
        a = _s + "{"; // Standard terminator
        int n = a.size();
        tree.reserve(2 * n);
        
        tree.push_back(Node(-1, -1, -1)); 
        tree.push_back(Node(-1, -1, -1)); 
        ts = 2; tv = 0; tp = 0;
        
        tree[0].s = 1;
        for (int i = 0; i < 28; i++) tree[1].next[i] = 0;

        for (la = 0; la < (int)a.size(); ++la) {
            ukkadd(a[la] - 'a');
        }
        prepare(0, 0);
    }

    void ukkadd(int c) {
        suff:;
        if (get_r(tv) < tp) {
            if (tree[tv].next[c] == -1) {
                tree[tv].next[c] = ts;
                tree.push_back(Node(la, INF, tv));
                ts++;
                tv = tree[tv].s;
                tp = get_r(tv) + 1;
                goto suff;
            }
            tv = tree[tv].next[c];
            tp = tree[tv].l;
        }
        if (tp == -1 || c == a[tp] - 'a') {
            tp++;
        } else {
            int old_tv = tv;
            int split_node = ts++;
            tree.push_back(Node(tree[old_tv].l, tp - 1, tree[old_tv].p));
            
            tree[tree[split_node].p].next[a[tree[split_node].l] - 'a'] = split_node;
            tree[split_node].next[a[tp] - 'a'] = old_tv;
            tree[old_tv].l = tp;
            tree[old_tv].p = split_node;
            
            int leaf = ts++;
            tree.push_back(Node(la, INF, split_node));
            tree[split_node].next[c] = leaf;
            
            tv = tree[tree[split_node].p].s;
            tp = tree[split_node].l;
            while (tp <= get_r(split_node)) {
                tv = tree[tv].next[a[tp] - 'a'];
                tp += get_r(tv) - tree[tv].l + 1;
            }
            if (tp == get_r(split_node) + 1) tree[split_node].s = tv;
            else tree[split_node].s = ts; 
            
            tp = get_r(tv) - (tp - get_r(split_node)) + 2;
            goto suff;
        }
    }

    int get_r(int v) {
        return min(tree[v].r, la);
    }

    void prepare(int v, int d) {
        bool is_leaf = true;
        tree[v].depth = d;
        for (int i = 0; i < 28; i++) {
            int child = tree[v].next[i];
            if (child != -1) {
                is_leaf = false;
                prepare(child, d + (get_r(child) - tree[child].l + 1));
                tree[v].leaf_count += tree[child].leaf_count;
            }
        }
        if (is_leaf) tree[v].leaf_count = 1;
    }

	// Longest repeated substring
    string longest_repeated_substring() {
        int max_d = 0;
        int best_v = 0;
        for (int i = 0; i < ts; i++) {
            if (tree[i].leaf_count > 1 && tree[i].depth > max_d) {
                max_d = tree[i].depth;
                best_v = i;
            }
        }
        if (best_v == 0) return "";
        
        // Backtrack to find the full path
        string res = "";
        int curr = best_v;
        while (curr != 0) {
            int node_l = tree[curr].l;
            int node_len = get_r(curr) - tree[curr].l + 1;
            res = a.substr(node_l, node_len) + res;
            curr = tree[curr].p;
        }
        return res;
    }

	// Pattern occurrence count
    int count_occurrences(string pattern) {
        int v = 0, p = 0;
        for (char ch : pattern) {
            int c = ch - 'a';
            if (p > get_r(v)) {
                if (tree[v].next[c] == -1) return 0;
                v = tree[v].next[c];
                p = tree[v].l;
            }
            if (a[p] != ch) return 0;
            p++;
        }
        return tree[v].leaf_count;
    }

	// Distrinct substrings
    long long count_distinct_substrings() {
        long long total = 0;
        for (int i = 1; i < ts; i++) {
            int length = get_r(i) - tree[i].l + 1;
            if (tree[i].next[26] != -1 || tree[i].r == INF) {
                length--; 
            }
            total += max(0, length);
        }
        return total;
    }
};


string s = "banana";
SuffixTree st(s);
st.longest_repeated_substring();
st.count_occurrences("ana");
st.count_distinct_substrings();