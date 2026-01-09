struct node2D {
    int s, e, m;
    node1D *maxi;
    node2D *l, *r;
    node2D(int a, int b, int c, int d) {
        s = a; e = b; m = (s+e)/2;
        maxi = new node1D(c, d);
        if (s != e) {
            l = new node2D(s, m, c, d);
            r = new node2D(m+1, e, c, d);
        }
    }
    void pu(int a, int b, int v) {
        if (s == e) { maxi->pu(b, v); return; }
        if (a <= m) l->pu(a, b, v);
        else r->pu(a, b, v);
        maxi->pu(b, max(l->maxi->rq(b, b), r->maxi->rq(b, b)));
    }
    int rq(int a, int b, int c, int d) {
        if (s == a && e == b) return maxi->rq(c, d);
        if (b <= m) return l->rq(a, b, c, d);
        if (a > m) return r->rq(a, b, c, d);
        return max(l->rq(a, m, c, d), r->rq(m+1, b, c, d));
    }
} *root;

root = new node(0, n-1, 0, n-1);