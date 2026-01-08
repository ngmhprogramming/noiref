// For adjacency lists
deque<int> dq;
dist[s] = 0;
dq.push(s);
while (!dq.empty()) {
	int u = dq.front(); dq.pop();
	for (int e : adjlist[u]) {
		int v = e.first, w = e.second;
		if (dist[v] > dist[u] + w) {
			dist[v] = dist[u] + w;
			if (w == 0) dq.push_front(v);
			else dq.push_back(v);
		}
	}
}