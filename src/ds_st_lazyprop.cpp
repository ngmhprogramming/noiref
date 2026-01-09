struct node {
    int s, e, m, v, lazy;
    node *l, *r;
    node(int _s, int _e) {
        s = _s; e = _e; m = (s+e)/2; v = lazy = 0;
        if (s != e) {
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }
    
	int pu() {
		if (s == e) { v += lazy; lazy = 0; return v; }
		v += lazy;
		l->lazy += lazy; r->lazy += lazy;
		lazy = 0;
		return v;
	}

	void ru(int x, int y, int z) {
		if (s == x && e == y) { lazy += z; return; }
		if (y <= m) l->ru(x, y, z);
		else if (x > m) r->ru(x, y, z);
		else l->ru(x, m, z), r->ru(m+1, y, z);
		v = max(l->pu(), r->pu());
	}

	int rq(int x, int y) {
		pu();
		if (s == x && e == y) return pu();
		if (y <= m) return l->rq(x, y);
		if (x > m) return r->rq(x, y);
		return max(l->rq(x, m), r->rq(m+1, y));
	}
} *root;

root = new node(0, n-1);