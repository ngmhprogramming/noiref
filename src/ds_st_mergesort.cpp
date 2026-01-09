struct node {
    int s, e, m;
	vector<int> v;
    node *l, *r;
	node(int _s, int _e) {
		s = _s; e = _e; m = (s+e)/2;
		if (s != e) {
			l = new node(s, m);
			r = new node(m+1, e);
		}
	}
	void insert(int x, int y) {
		if (s == e) { v.push_back(y); return; }
		if (x > m) r->insert(x, y);
		if (x <= m) l->insert(x, y);
		v.push_back(y);
	}
	void build(){
		if (s == e) return;
		l->build();
		r->build();
		sort(v.begin(), v.end());
	}
	int countLessEqual(int x, int y, int k) {
		if (x > y) return 0;
		if (s == x && e == y) {
			return upper_bound(v.begin(), v.end(), k)-v.begin();
		}
		if (x > m) return r->countLessEqual(x, y, k);
		if (y <= m) return l->countLessEqual(x, y, k);
		return l->countLessEqual(x, m, k)+r->countLessEqual(m+1, y, k);
	}
	int kthSmallest(int x, int y, int k) {
		int mini = 0, maxi = (1 << 30);
		int ans = mini, gap = maxi;
		while (gap > 0) {
			while (ans + gap <= maxi && countLessEqual(x, y, ans + gap) < k) {
				ans += gap;
			}
			gap >>= 1;
		}
		return ans + 1;
	}
	int rangeMax(int x, int y) {
		if (x > y) return 0;
		if (s == x && e == y) return v.back();
		if (x > m) return r->rangeMax(x, y);
		if (y <= m) return l->rangeMax(x, y);
		return max(l->rangeMax(x, m), r->rangeMax(m+1, y));
	}
} *root;

root = new node(0, n-1);