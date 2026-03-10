class Edmonds {
private:
    int n, m;
    int mcbm = 0;
    vector<int> mate, p, d, bl;
    vector<vector<int>> g;
    vector<vector<int>> b;

    int find_lca(int x, int y, vector<int>& p, vector<int>& bl,
				 const vector<int>& mate) {
        vector<bool> used(n, false);
        while (true) {
            x = bl[x];
            used[x] = true;
            if (mate[x] == -1) break;
            x = p[mate[x]];
        }
        while (true) {
            y = bl[y];
            if (used[y]) return y;
            y = p[mate[y]];
        }
    }

    void update_path(int x, int y, int lca, vector<int>& p, vector<int>& d,
					 vector<int>& bl, queue<int>& Q, const vector<int>& mate) {
        while (bl[x] != lca) {
            p[x] = y;
            y = mate[x];
            if (d[y] == 1) { d[y] = 0; Q.push(y); }
            if (bl[x] == x) bl[x] = lca;
            if (bl[y] == y) bl[y] = lca;
            x = p[y];
        }
    }

public:
    Edmonds(int n) : n(n), m(n + n / 2), mate(n, -1), p(n), d(n),
					 bl(n), g(n, vector<int>(n, -1)) {}

    void addEdge(int u, int v) {
        g[u][v] = g[v][u] = 1;
    }

    int compute() {
        mcbm = 0;
        fill(mate.begin(), mate.end(), -1);
        for (int i = 0; i < n; ++i) {
            if (mate[i] == -1) {
                queue<int> Q;
                Q.push(i);
                fill(p.begin(), p.end(), -1);
                fill(d.begin(), d.end(), -1);
                iota(bl.begin(), bl.end(), 0);
                d[i] = 0;

                while (!Q.empty()) {
                    int u = Q.front(); Q.pop();
                    for (int v = 0; v < n; ++v) {
                        if (g[u][v] == -1 || bl[u] == bl[v]) continue;
                        if (d[v] == -1) {
                            d[v] = 1; p[v] = u;
                            if (mate[v] == -1) {
                                while (v != -1) {
                                    int pv = p[v];
                                    int ppv = mate[pv];
                                    mate[v] = pv; mate[pv] = v;
                                    v = ppv;
                                }
                                mcbm++; goto next_i;
                            }
                            d[mate[v]] = 0; Q.push(mate[v]);
                        } else if (d[v] == 0) {
                            int lca = find_lca(u, v, p, bl, mate);
                            update_path(u, v, lca, p, d, bl, Q, mate);
                            update_path(v, u, lca, p, d, bl, Q, mate);
                        }
                    }
                }
            }
            next_i:;
        }
        return mcbm;
    }

    int getMCBM() { return mcbm; }
    int getMatched(int u) { return mate[u]; }
};

Edmonds solver(N);
solver.addEdge(u, v);
solver.compute();
solver.getMatched(i);