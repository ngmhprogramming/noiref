// For adjacency lists
visited[s] = 1;
dist[s] = 0;
q.push(s);
while (!q.empty()) {
	int f = q.front(); q.pop();
	for (int i : adjlist[f]) {
		if (!visited[i]) {
			q.push(i);
			visited[i] = 1;
			dist[i] = dist[f] + 1;
		}
	}
}