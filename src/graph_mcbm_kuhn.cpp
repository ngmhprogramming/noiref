int n, mcbms = 0, miss = 0;
vector<int> match;
vector<bool> vis;
vector<vector<int>> adj;
vector<int> left;

// dfs for augmenting path
bool dfs(int u) {
	for (int v : adj[u]) {
		if (!vis[v]) {
			vis[v] = true;
			if (match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				match[u] = v;
				return true;
			}
		}
	}
	return false;
}

void mcbm() {
	match.assign(n, -1);
	mcbms = 0;
	// greedy initial matching
	for (int u : left) {
		for (int v : adj[u]) {
			if (match[v] == -1) {
				match[v] = u;
				match[u] = v;
				mcbms++;
				break;
			}
		}
	}
	// dfs augmenting paths for unmatched
	for (int u : left) {
		if (match[u] == -1) {
			vis.assign(n, false);
			if (dfs(u)) mcbms++;
		}
	}
	miss = n - mcbms;
}