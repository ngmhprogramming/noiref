vector<int> dist(n, INF);
vector<int> inQueue(n, 0);
queue<int> q;
dist[s] = 0;
q.push(s);
inQueue[s]++;
bool negCycle = false;
while (!q.empty()) {
	int u = q.front(); q.pop();
	inQueue[u]--;
	for (Edge e : adj[u]) {
		if (dist[e.v] > dist[u] + e.w) {
			dist[e.v] = dist[u] + e.w;
			if (inQueue[e.v] == 0) {
				q.push(e.v);
				inQueue[e.v]++;
				if (inQueue[e.v] > n) {
					negCycle = true;
					break;
				}
			}
		}
	}
	if (negCycle) break;
}