class HopcroftKarp {
private:
    int n, m;
    int mcbm = 0;
    const int INF = INT_MAX;
    vector<vector<int>> adj;
    vector<int> pairU, pairV, dist;

    bool bfs() {
        queue<int> q;
        for (int u = 0; u < n; ++u) {
            if (pairU[u] == -1) {
                dist[u] = 0;
                q.push(u);
            } else {
                dist[u] = INF;
            }
        }
        bool found = false;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : adj[u]) {
                if (pairV[v] == -1) {
                    found = true;
                } else if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
        return found;
    }

    bool dfs(int u) {
        for (int v : adj[u]) {
            if (pairV[v] == -1 ||
               (dist[pairV[v]] == dist[u] + 1 && dfs(pairV[v]))) {
                pairU[u] = v;
                pairV[v] = u;
                return true;
            }
        }
        dist[u] = INF;
        return false;
    }

public:
    HopcroftKarp(int n, int m) : n(n), m(m), adj(n),
                                 pairU(n, -1), pairV(m, -1), dist(n) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    int compute() {
        pairU.assign(n, -1);
        pairV.assign(m, -1);
        dist.assign(n, 0);

        mcbm = 0;
        while (bfs()) {
            for (int u = 0; u < n; ++u) {
                if (pairU[u] == -1 && dfs(u)) {
                    mcbm++;
                }
            }
        }
        return mcbm;
    }

    int getMCBM() { return mcbm; }
    int getMIS() { return n + m - mcbm; }

    int getMatchedU(int u) { return pairU[u]; }
    int getMatchedV(int v) { return pairV[v]; }
};

HopcroftKarp solver(3, 3); // (N, M)
solver.addEdge(0, 0); // (L, R)
solver.compute(); // DON'T FORGET THIS!
solver.getMCBM();
solver.getMIS();
solver.getMatchedU(0); // Left side
solver.getMatchedV(0); // Right side