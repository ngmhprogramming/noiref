struct Node {
	ll m, c;
	Node *lc, *rc;
	Node(ll _m = 0, ll _c = -INF) {
		m = _m; c = _c;
		lc = nullptr; rc = nullptr;
	}
	ll value(ll x) {
		return m * x + c;
	}
	void insert(ll nm, ll nc, ll l, ll r) {
		ll mid = (l+r)/2;
		bool leftCheck = nm * l + nc > value(l);
		bool midCheck = nm * mid + nc > value(mid);
		if (midCheck) {
			swap(m, nm);
			swap(c, nc);
		}
		if (r-l == 1) return;
		if (leftCheck != midCheck) {
			if (!lc) lc = new Node();
			lc->insert(nm, nc, l, mid);
		} else {
			if (!rc) rc = new Node();
			rc->insert(nm, nc, mid, r);
		}
	}
	ll query(ll x, ll l, ll r) {
		ll res = value(x);
		if (r-l == 1) return res;
		ll mid = (l+r)/2;
		if (x < mid && lc) return max(res, lc->query(x, l, mid));
		if (x >= mid && rc) return max(res, rc->query(x, mid, r));
		return res;
	}
};

// Queries are on half open [L, R)
// Example: Commando
Node *root = new Node();
root->insert(0, 0, MINX, MAXX);
for (int i = 1; i <= n; i++) {
	// query lct
	ll x = p[i];
	ll best = root->query(x, MINX, MAXX);
	dp[i] = best + a*x*x + b*x + c;
	// update lct
	ll m = -2*a*x;
	ll c = dp[i] + a*x*x - b*x;
	root->insert(m, c, MINX, MAXX);
}