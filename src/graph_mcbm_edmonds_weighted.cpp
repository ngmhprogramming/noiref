// jacobtpl on yosupo

template<int SZ>
class WeightedMatching {
    struct Edge { int u, v, w; };
    Edge g[SZ * 2][SZ * 2];
    int N, NX, lab[SZ * 2], match[SZ * 2], slack[SZ * 2], st[SZ * 2];
    int par[SZ * 2], floFrom[SZ * 2][SZ], S[SZ * 2], aux[SZ * 2];
    vector<int> flo[SZ * 2];
    queue<int> q;

public:
    void init(int _N) {
        N = _N; NX = N;
        for (int i = 0; i <= 2 * N; ++i) {
            for (int j = 0; j <= 2 * N; ++j) g[i][j] = {i, j, 0};
            flo[i].clear(); match[i] = 0; st[i] = i;
        }
    }

    void addEdge(int u, int v, int w) {
        g[u][v].w = g[v][u].w = w;
    }

    int eDelta(Edge e) { return lab[e.u] + lab[e.v] - g[e.u][e.v].w * 2; }

    void updSlack(int u, int x) {
        if (!slack[x] || eDelta(g[u][x]) < eDelta(g[slack[x]][x])) {
            slack[x] = u;
        }
    }

    void setSlack(int x) {
        slack[x] = 0;
        for (int u = 1; u <= N; ++u) {
            if (g[u][x].w > 0 && st[u] != x && S[st[u]] == 0) {
                updSlack(u, x);
            }
        }
    }

    void qPush(int x) {
        if (x <= N) q.push(x);
        else for (int t : flo[x]) qPush(t);
    }

    void setSt(int x, int b) {
        st[x] = b; if (x > N) for (int t : flo[x]) setSt(t, b);
    }

    int getPr(int b, int xr) {
        int pr = find(flo[b].begin(), flo[b].end(), xr) - flo[b].begin();
        if (pr & 1) {
            reverse(flo[b].begin() + 1, flo[b].end());
            return (int)flo[b].size() - pr;
        }
        return pr;
    }

    void setMatch(int u, int v) {
        Edge e = g[u][v]; match[u] = e.v; if (u <= N) return;
        int xr = floFrom[u][e.u], pr = getPr(u, xr);
        for (int i = 0; i < pr; ++i) setMatch(flo[u][i], flo[u][i ^ 1]);
        setMatch(xr, v);
        rotate(flo[u].begin(), flo[u].begin() + pr, flo[u].end());
    }

    void augment(int u, int v) {
        while (1) {
            int xnv = st[match[u]]; setMatch(u, v);
            if (!xnv) return;
            setMatch(xnv, st[par[xnv]]);
            u = st[par[xnv]], v = xnv;
        }
    }

    int lca(int u, int v) {
        static int t = 0;
        for (++t; u || v; swap(u, v)) {
            if (!u) continue;
            if (aux[u] == t) return u;
            aux[u] = t; u = st[match[u]];
            if (u) u = st[par[u]];
        }
        return 0;
    }

    void addBlossom(int u, int anc, int v) {
        int b = N + 1; while (b <= NX && st[b]) ++b;
        if (b > NX) ++NX;
        lab[b] = S[b] = 0; match[b] = match[anc]; flo[b] = {anc};
        auto blossom = [&](int x) {
            for (int y; x != anc; x = st[par[y]]) {
                flo[b].push_back(x), flo[b].push_back(y = st[match[x]]), qPush(y);
            }
        };
        blossom(u);
        reverse(flo[b].begin() + 1, flo[b].end());
        blossom(v);
        setSt(b, b);
        for (int x = 1; x <= NX; ++x) g[b][x].w = g[x][b].w = 0;
        for (int x = 1; x <= N; ++x) floFrom[b][x] = 0;
        for (int xs : flo[b]) {
            for (int x = 1; x <= NX; ++x) {
                if (g[b][x].w == 0 || eDelta(g[xs][x]) < eDelta(g[b][x])) {
                    g[b][x] = g[xs][x], g[x][b] = g[x][xs];
                }
            }
            for (int x = 1; x <= N; ++x) {
                if (floFrom[xs][x]) floFrom[b][x] = xs;
            }
        }
        setSlack(b);
    }

    void expandBlossom(int b) {
        for (int t : flo[b]) setSt(t, t);
        int xr = floFrom[b][g[b][par[b]].u], pr = getPr(b, xr);
        for (int i = 0; i < pr; i += 2) {
            int xs = flo[b][i], xns = flo[b][i + 1];
            par[xs] = g[xns][xs].u;
            S[xs] = 1;
            S[xns] = slack[xs] = slack[xns] = 0;
            qPush(xns);
        }
        S[xr] = 1; par[xr] = par[b];
        for (int i = pr + 1; i < (int)flo[b].size(); ++i) {
            int xs = flo[b][i]; S[xs] = -1; setSlack(xs);
        }
        st[b] = 0;
    }

    bool onFoundEdge(Edge e) {
        int u = st[e.u], v = st[e.v];
        if (S[v] == -1) {
            par[v] = e.u; S[v] = 1; slack[v] = 0;
            int nu = st[match[v]]; S[nu] = slack[nu] = 0; qPush(nu);
        } else if (S[v] == 0) {
            int anc = lca(u, v);
            if (!anc) { augment(u, v); augment(v, u); return 1; }
            addBlossom(u, anc, v);
        }
        return 0;
    }

    bool matching() {
        q = queue<int>();
        for (int x = 1; x <= NX; ++x) {
            S[x] = -1; slack[x] = 0;
            if (st[x] == x && !match[x]) par[x] = S[x] = 0, qPush(x);
        }
        if (q.empty()) return 0;
        while (1) {
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v = 1; v <= N; ++v) {
                    if (g[u][v].w > 0 && st[u] != st[v]) {
                        if (eDelta(g[u][v]) == 0) {
                            if (onFoundEdge(g[u][v])) return 1;
                        }
                        else updSlack(u, st[v]);
                    }
                }
            }
            int d = INT_MAX;
            for (int b = N + 1; b <= NX; ++b) {
                if (st[b] == b && S[b] == 1) d = min(d, lab[b] / 2);
            }
            for (int x = 1; x <= NX; ++x) if (st[x] == x && slack[x]) {
                if (S[x] == -1) d = min(d, eDelta(g[slack[x]][x]));
                else if (S[x] == 0) d = min(d, eDelta(g[slack[x]][x]) / 2);
            }
            for (int u = 1; u <= N; ++u) {
                if (S[st[u]] == 0) { if (lab[u] <= d) return 0; lab[u] -= d; }
                else if (S[st[u]] == 1) lab[u] += d;
            }
            for (int b = N + 1; b <= NX; ++b) {
                if (st[b] == b && S[b] != -1) {
                    lab[b] += (S[b] == 0 ? 1 : -1) * d * 2;
                }
            }
            q = queue<int>();
            for (int x = 1; x <= NX; ++x) {
                if (st[x] == x && slack[x] && st[slack[x]] != x
                    && eDelta(g[slack[x]][x]) == 0) {
                    if (onFoundEdge(g[slack[x]][x])) return 1;
                }
            }
            for (int b = N + 1; b <= NX; ++b) {
                if (st[b] == b && S[b] == 1 && lab[b] == 0) expandBlossom(b);
            }
        }
        return 0;
    }

    pair<int, long long> compute() {
        int wMax = 0;
        for (int u = 1; u <= N; ++u) for (int v = 1; v <= N; ++v) {
            floFrom[u][v] = (u == v ? u : 0); wMax = max(wMax, g[u][v].w);
        }
        for (int u = 1; u <= N; ++u) lab[u] = wMax;
        int num = 0; long long wei = 0;
        while (matching()) ++num;
        for (int u = 1; u <= N; ++u) {
            if (match[u] && match[u] < u) wei += g[u][match[u]].w;
        }
        return {num, wei};
    }

    int getMatched(int u) { return match[u + 1] - 1; }
};

WeightedMatching<N> solver;
solver.init(N);
solver.addEdge(u + 1, v + 1, w); // 1-indexed
auto res = solver.compute(); // (num, weight)
solver.getMatched(i); // check that it's not -1