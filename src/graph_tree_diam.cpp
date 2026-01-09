pi dfs(int x, int p, int d) {
	pi b = {x, d};
	for (pi y : adj[x]) {
		if (y.first != p) {
			pi c = dfs(y.first, x, d + y.second);
			if (c.second > b.second) b = c;
		}
	}
	return b;
}
pi s = dfs(0, -1, 0);
pi e = dfs(s.first, -1, 0);
// e.second gives diameter
// For even diameter, centroid is at e.second / 2
// For odd diameter, centroid is at e.second / 2 and e.second / 2 + 1