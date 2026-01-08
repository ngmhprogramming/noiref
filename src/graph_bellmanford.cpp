vector<int> dist(n, INF);
dist[s] = 0;
bool negCycle = false;
for (int i = 1; i <= n; i++) {
	bool update = false;
	for (Edge e : edges) {
		if (dist[e.u] < INF && dist[e.v] > dist[e.u] + e.w) {
			dist[e.v] = dist[e.u] + e.w;
			update = true;
		}
	}
	if (!update) break;
	if (update && i == n) negCycle = true;
}