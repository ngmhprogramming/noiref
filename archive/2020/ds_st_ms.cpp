struct node {
    ll s, e, m, ps, ss, ms, ts;
    node *l, *r;
    node(ll _s, ll _e){
        s = _s; e = _e; m = (s+e)/2; ps = ss = ms = ts = 0;
        if(s != e){
            l = new node(s, m);
            r = new node(m+1, e);
        }
    }
    void pu(ll x, ll y){
        if(s == e){ ps = ss = ms = ts = y; return; }
        if(x <= m) l->pu(x, y);
        if(x > m) r->pu(x, y);
        //New Prefix Max - Left Prefix, Left + Right Prefix
        ps = max(l->ps, l->ts+r->ps);
        //New Suffix Max - Right Suffix, Left Suffix + Right
        ss = max(r->ss, r->ts+l->ss);
        //Total Sum - Left + Right
        ts = l->ts+r->ts;
        //Maxsum - Left Suffix + Right Prefix, Left, Right,
        //         Total, Left Maxsum, Right Maxsum
        ms = max({l->ss+r->ps, ps, ss, ts, l->ms, r->ms});
    }
    ll ans(){
        return ms;
    }
} *root;