vector<int> adj[MAXN];
vector<int> comps[MAXN];
set<int> adjscc[MAXN];
vector<int> idxs(MAXN, -1), low(MAXN, 0);
vector<bool> onStack(MAXN, false);
stack<int> st;
int dfsidx = 0, sccidx;
int comp[MAXN];

void scc(int u) {
	idxs[u] = low[u] = dfsidx++;
	st.push(u);
	onStack[u] = true;
	for (int v : adj[u]) {
		if (idxs[v] == -1) {
			scc(v);
			low[u] = min(low[u], low[v]);
		} else if (onStack[v]) {
			low[u] = min(low[u], idxs[v]);
		}
	}
	if (low[u] == idxs[u]) {
		// u is a root of an scc
		comps[sccidx].clear();
		int w;
		do {
			w = st.top(); st.pop();
			onStack[w] = false;
			comps[sccidx].push_back(w);
			comp[w] = sccidx;
		} while (w != u);
		sccidx++;
	}
}

for (int i = 1; i <= n; i++) {
	if (idxs[i] == -1) scc(i);
}

for (int u = 1; u <= n; u++) {
	for (int v : adj[u]) {
		if (comp[u] != comp[v]) adjscc[comp[u]].insert(comp[v]);
	}
}

// dfs idxs now range from 0 to dfsidx-1
// scc idxs now range from 0 to sccidx-1