vector<int> adj[MAXN];
vector<int> dep(MAXN, 0), low(MAXN, 0), par(MAXN, -1);
vector<int> chi(MAXN, 0), atp(MAXN, 0);
vector<bool> vis(MAXN, false);
vector<pi> bridges;

void tarjan(int u, int d) {
	vis[u] = true;
	dep[u] = low[u] = d;
	chi[u] = 0; atp[u] = 1;
	for (int v : adj[u]) {
		if (!vis[v]) {
			par[v] = u;
			chi[u]++;
			tarjan(v, d+1);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dep[u]) atp[u]++;
			if (low[v] > dep[u]) bridges.push_back({u, v});
		} else if (v != par[u]) {
			low[u] = min(low[u], dep[v]);
		}
	}
}

tarjan(0, 0);
// handle root separately since it has no parents
atp[0] = chi[0];
// atp stores number of components separated upon removal
// bridges stores all bridges in the graph