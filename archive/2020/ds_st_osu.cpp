struct node {
	ll s, e, m, it;
	ordered_set v;
	node *l, *r;
	node(ll _s, ll _e){
		s = _s; e = _e; m = (s+e)/2;
		if(s != e){
			l = new node(s, m);
			r = new node(m+1, e);
		}
	}
	void pu(ll x, ll y){
		if(s == e){ v.insert(pi(y, x)); return; }
		if(x > m) r->pu(x, y);
		if(x <= m) l->pu(x, y);
		v.insert(pi(y, x));
	}
	void pc(ll x, ll o, ll y){
		if(s == e){ v.clear(); v.insert(pi(y, x)); return; }
		if(x > m) r-> pc(x, o, y);
		if(x <= m) l->pc(x, o, y);
		v.erase(pi(o, x)); v.insert(pi(y, x));
	}
	ll rq(ll x, ll y, ll k){
		if(x > y) return 0;
		if(s == x && e == y){
			int ans = v.order_of_key(pi(k, LLONG_MAX));
			return v.size()-ans;
		}
		if(x > m) return r->rq(x, y, k);
		if(y <= m) return l->rq(x, y, k);
		return l->rq(x, m, k)+r->rq(m+1, y, k);
    }
} *root;