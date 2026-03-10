class Hungarian {
private:
    int n, m;
    int minCost = 0;
    const int INF = INT_MAX / 4; // prevent overflow
    vector<vector<int>> cost;
    vector<int> u, v, p, way;

public:
    Hungarian(int n, int m) : n(n), m(m), cost(n + 1, vector<int>(m + 1, 0)), 
                              u(n + 1), v(m + 1), p(m + 1), way(m + 1) {}

    void setWeight(int i, int j, int weight) {
        cost[i + 1][j + 1] = weight;
    }

    int compute() {
        fill(u.begin(), u.end(), 0);
        fill(v.begin(), v.end(), 0);
        fill(p.begin(), p.end(), 0);
        fill(way.begin(), way.end(), 0);

        for (int i = 1; i <= n; ++i) {
            p[0] = i;
            int j0 = 0;
            vector<int> minv(m + 1, INF);
            vector<bool> used(m + 1, false);
            do {
                used[j0] = true;
                int i0 = p[j0], delta = INF, j1 = 0;
                for (int j = 1; j <= m; ++j) {
                    if (!used[j]) {
                        int cur = cost[i0][j] - u[i0] - v[j];
                        if (cur < minv[j]) {
                            minv[j] = cur;
                            way[j] = j0;
                        }
                        if (minv[j] < delta) {
                            delta = minv[j];
                            j1 = j;
                        }
                    }
                }
                for (int j = 0; j <= m; ++j) {
                    if (used[j]) u[p[j]] += delta, v[j] -= delta;
                    else minv[j] -= delta;
                }
                j0 = j1;
            } while (p[j0] != 0);
            do {
                int j1 = way[j0];
                p[j0] = p[j1];
                j0 = j1;
            } while (j0);
        }
        minCost = -v[0];
        return minCost;
    }

    int getMinCost() { return minCost; }

    int getMatchedU(int u) {
        for (int j = 1; j <= m; ++j) if (p[j] == u + 1) return j - 1;
        return -1;
    }
};

// requires N <= M!

// min weight matching
Hungarian minSolver(3, 3);
minSolver.setWeight(0, 0, 10);
minSolver.compute();
minSolver.getMinCost();

// max weight matching - negate edges!
Hungarian maxSolver(3, 3);
maxSolver.setWeight(0, 0, -10);
maxSolver.compute();
-maxSolver.getMinCost();