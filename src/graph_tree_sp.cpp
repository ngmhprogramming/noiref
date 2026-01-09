int distance(int x, int y) {
	return dist[x] + dist[y] - 2 * dist[lca(x, y)];
}