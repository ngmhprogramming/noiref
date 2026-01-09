void dfs(int x) {
	if (v[x]) return;
	v[x] = 1;
	for (int y : adj[x]) dfs(y);
	topo.push_back(x);
}
for (int i = 0; i < n; i++) dfs(i);
reverse(topo.begin(), topo.end());