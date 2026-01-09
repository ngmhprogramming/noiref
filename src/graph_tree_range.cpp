int dfs(int x, int p) {
	pre[x] = c++;
	rig[pre[x]] = pre[x];
	for (int y : adj[x]) {
		if (y != p) {
			rig[pre[x]] = max(rig[pre[x]], dfs(y, x));
		}
	} 
	return rig[pre[x]];
}
// Subtree -> pre[x], rig[pre[x]]
// Node Index -> pre[x]
// Range of Children -> pre[x]+1, rig[pre[x]]