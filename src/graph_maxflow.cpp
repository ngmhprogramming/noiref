struct Edge {
	int v;
	int cap, flow;
	int rid;
}

vector<vector<Edge>> adj;
vector<int> dist, ptr;

// add a directed edge, manually add both ways for undirected
void addEdge(int u, int v, int cap) {
	int id = adj[u].size();
	int rid = adj[v].size();
	adj[u].push_back({ v, cap, 0, rid }); // regular edge
	adj[v].push_back({ u, 0, 0, id }); // residual edge
}

// build level graph
// only use edges with residual capacity left
bool bfs(int s, int t) {
	fill(dist.begin(), dist.end(), -1);
	queue<int> q;
	dist[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (Edge e : adj[u]) {
			if (e.cap == e.flow) continue; // no residual capacity
			if (dist[e.v] != -1) continue;
			dist[e.v] = dist[u] + 1;
			q.push(e.v);
		}
	}
	return dist[t] != -1;
}

// find blocking flow
// moves along shortest paths
int dfs(int u, int t, int flow) {
	if (u == t) return flow;
	for (; ptr[u] < adj[u].size(); ptr[u]++) {
		Edge &e = adj[u][ptr[u]];
		if (dist[u] + 1 != dist[e.v]) continue;
		if (e.cap == e.flow) continue;
		int cflow = min(flow, e.cap - e.flow); // try pushing available
		cflow = dfs(e.v, t, cflow);
		if (cflow > 0) {
			// on success, augment flow forward and subtract on reverse
			e.flow += cflow;
			adj[e.v][e.rid].flow -= cflow;
			return cflow;
		}
	}
	return 0;
}

// repeatedly BFS to build level graph and DFS to find blocking flow
int flow(int s, int t) {
	int res = 0;
	while (bfs(s, t)) {
		fill(ptr.begin(), ptr.end(), 0);
		int cflow = dfs(s, t, INF);
		while (cflow > 0) {
			res += cflow;
			cflow = dfs(s, t, INF);
		}
	}
	return res;
}

flow(1, n);