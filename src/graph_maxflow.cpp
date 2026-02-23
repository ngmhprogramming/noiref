const long long INF = 1e18;

struct Dinic {
    struct Edge {
        int u, v;
        long long cap, flow;
        int rid;
        int id; 
    };

    struct EdgeRef {
        int u, idx;
    };

    vector<vector<Edge>> adj;
    vector<long long> dist, ptr;
    vector<EdgeRef> edge_lookup;

    Dinic(int n) : adj(n), dist(n), ptr(n) {}

    inline int in(int u) { return 2 * u; }
    inline int out(int u) { return 2 * u + 1; }

    int addNodeCap(int u, long long cap) {
        return addEdge(in(u), out(u), cap);
    }

    int addEdgeBetweenNodes(int u, int v, long long cap) {
        return addEdge(out(u), in(v), cap);
    }

    int addEdge(int u, int v, long long cap) {
        int u_idx = adj[u].size();
        int v_idx = adj[v].size();
        int lookup_id = edge_lookup.size();
        edge_lookup.push_back({u, u_idx});
        adj[u].push_back({u, v, cap, 0, v_idx, lookup_id});
        adj[v].push_back({v, u, 0, 0, u_idx, -1}); 
        return lookup_id;
    }

    void updateCap(int id, long long new_cap) {
        EdgeRef ref = edge_lookup[id];
        adj[ref.u][ref.idx].cap = new_cap;
    }

    long long getFlow(int id) {
        EdgeRef ref = edge_lookup[id];
        return adj[ref.u][ref.idx].flow;
    }

    bool bfs(int s, int t) {
        fill(dist.begin(), dist.end(), -1);
        queue<int> q;
        dist[s] = 0;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto &e : adj[u]) {
                if (e.cap - e.flow > 0 && dist[e.v] == -1) {
                    dist[e.v] = dist[u] + 1;
                    q.push(e.v);
                }
            }
        }
        return dist[t] != -1;
    }

    long long dfs(int u, int t, long long f) {
        if (u == t || f == 0) return f;
        for (; ptr[u] < adj[u].size(); ptr[u]++) {
            Edge &e = adj[u][ptr[u]];
            if (dist[u] + 1 != dist[e.v] || e.cap - e.flow == 0) continue;
            long long pushed = dfs(e.v, t, min(f, e.cap - e.flow));
            if (pushed > 0) {
                e.flow += pushed;
                adj[e.v][e.rid].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    long long flow(int s, int t) {
        long long res = 0;
        while (bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while (long long cflow = dfs(s, t, INF)) res += cflow;
        }
        return res;
    }

	void resetFlow() {
        for (int i = 0; i < adj.size(); i++) {
            for (auto &e : adj[i]) {
                e.flow = 0;
            }
        }
    }

	vector<int> getSComponent() {
        vector<int> s_comp;
        for (int i = 0; i < adj.size(); i++) {
            if (dist[i] != -1) s_comp.push_back(i);
        }
        return s_comp;
    }

    vector<int> getTComponent() {
        vector<int> t_comp;
        for (int i = 0; i < adj.size(); i++) {
            if (dist[i] == -1) t_comp.push_back(i);
        }
        return t_comp;
    }

	vector<Edge> getCutEdges() {
        vector<Edge> cut;
        for (int u = 0; u < adj.size(); u++) {
            if (dist[u] != -1) { 
                for (auto &e : adj[u]) {
                    if (e.id != -1 && dist[e.v] == -1) {
                        cut.push_back(e);
                    }
                }
            }
        }
        return cut;
    }

    vector<Edge> getUsedEdges() {
        vector<Edge> used;
        for (int u = 0; u < adj.size(); u++) {
            for (auto &e : adj[u]) {
                if (e.id != -1 && e.flow > 0) {
                    used.push_back(e);
                }
            }
        }
        return used;
    }
};

Dinic solver(n); // Use n for standard max flow
Dinic solver(2 * n); // Use 2 * n for max flow with node capacities

// Returns edge id
solver.addEdge(u, v, c); // Add edge for standard max flow
// For graph with node capacities
solver.in(u); // Logical input vertex
solver.out(u); // Logical output vertex
solver.addEdgeBetweenNodes(u, v, c); // Add edge between nodes
solver.addNodeCap(u, c); // Add node capacity

solver.updateCap(edge_id, c); // Set new edge capacity

// Returns flow value
solver.resetFlow();
solver.flow(s, t); // Get max flow
solver.getFlow(edge_id); // Access specific flow value on edge

// Accesssing more information
vector<int> s_side = solver.getSComponent(); // Get source component
vector<int> t_side = solver.getTComponent(); // Get sink component
vector<Dinic::Edge> cut = solver.getCutEdges(); // Get edges on min cut
vector<Dinic::Edge> es = solver.getUsedEdges(); // Get edges used in max flow