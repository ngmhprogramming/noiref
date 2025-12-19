struct node {
    int s, e, m, it;
	vector<int> v;
    node *l, *r;
	node(int _s, int _e){
		s = _s; e = _e; m = (s+e)/2;
		if(s != e){
			l = new node(s, m);
			r = new node(m+1, e);
		}
	}
	void pu(int x, int y){
		if(s == e){ v.push_back(y); return; }
		if(x > m) r->pu(x, y);
		if(x <= m) l->pu(x, y);
		v.push_back(y);
	}
	void sorty(){
		if(s == e) return;
		l->sorty();
		r->sorty();
		sort(v.begin(), v.end());
	}
	int rq(int x, int y, int k){
		if(x > y) return 0;
		if(s == x && e == y) return upper_bound(v.begin(), v.end(), k)-v.begin();
		if(x > m) return r->rq(x, y, k);
		if(y <= m) return l->rq(x, y, k);
		return l->rq(x, m, k)+r->rq(m+1, y, k);
        }
	int mrq(int x, int y){
		if(x > y) return 0;
		if(s == x && e == y){ auto it = v.end(); it--; return *it; }
		if(x > m) return r->mrq(x, y);
		if(y <= m) return l->mrq(x, y);
		return max(l->mrq(x, m), r->mrq(m+1, y));
	}
} *root;