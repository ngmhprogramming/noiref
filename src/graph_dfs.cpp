// For adjacency lists
void dfs(int x, int p) {
    for (int y : adj[x]) {
        if (y != p) {
			dist[y] = dist[x]+1;
            dfs(y, x);
        }
    }
}