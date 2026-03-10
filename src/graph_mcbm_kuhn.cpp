class Kuhns {
private:
    int nL, nR;
    int mcbm = 0;
    vector<int> matchR;
    vector<int> matchL;
    vector<bool> vis;
    vector<vector<int>> adj;

    bool dfs(int u) {
        for (int v : adj[u]) {
            if (!vis[v]) {
                vis[v] = true;
                if (matchR[v] == -1 || dfs(matchR[v])) {
                    matchR[v] = u;
                    matchL[u] = v;
                    return true;
                }
            }
        }
        return false;
    }

public:
    Kuhns(int L, int R) : nL(L), nR(R), matchR(R, -1), matchL(L, -1),
						  vis(R), adj(L) {}

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void compute() {
        mcbm = 0;
        matchR.assign(nR, -1);
        matchL.assign(nL, -1);
        
        // greedy initial matching
        for (int u = 0; u < nL; ++u) {
            for (int v : adj[u]) {
                if (matchR[v] == -1) {
                    matchR[v] = u;
                    matchL[u] = v;
                    mcbm++;
                    break;
                }
            }
        }
        
        // dfs for augmenting paths
        for (int u = 0; u < nL; ++u) {
            if (matchL[u] == -1) {
                vis.assign(nR, false);
                if (dfs(u)) mcbm++;
            }
        }
    }

    int getMCBM() { return mcbm; }
    int getMIS() { return nL + nR - mcbm; }
    
    int getMatchedU(int u) { return matchL[u]; }
    int getMatchedV(int v) { return matchR[v]; }
};

Kuhns solver(3, 3); // (N, M)
solver.addEdge(0, 2); // (L, R)
solver.compute(); // DON'T FORGET THIS!
solver.getMCBM();
solver.getMIS();
solver.getMatchedU(0);
solver.getMatchedV(2);