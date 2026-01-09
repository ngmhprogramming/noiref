// Example: Xenia and Tree
// Update: Mark a node red
// Query: Find distance to closest red node to query node

int sz[MAXN], par[MAXN], lvl[MAXN];
ll dist[MAXN][MAXLOGN], best[MAXN];

// find subtree sizes
int dfsSize(int x, int p) {
	sz[x] = 1;
	for (int y : adj[x]) {
		if (lvl[y] != -1 || y == p) continue;
		sz[x] += dfsSize(y, x);
	}
	return sz[x];
}

// find centroid of each subtree
int dfsCentroid(int x, int p, int n) {
	for (int y : adj[x]) {
		if (lvl[y] != -1 || y == p) continue;
		if (sz[y] > n / 2) return dfsCentroid(y, x, n);
	}
	// current node is centroid
	return x;
}

void dfsDist(int x, int p, int level, ll d) {
	dist[x][level] = d;
	for (int y : adj[x]) {
		if (lvl[y] != -1 || y == p) continue;
		dfsDist(y, x, level, d + 1);
	}
}

void build(int x, int p, int level) {
	// find subtree sizes and centroid
	int size = dfsSize(x, -1);
	int cent = dfsCentroid(x, -1, size);
	if (p == -1) p = cent;
	par[cent] = p; // set parent of centroid to previous centroid
	lvl[cent] = level;
	dfsDist(cent, -1, level, 0);
	// recursively build subtrees
	for (int y : adj[cent]) {
		if (lvl[y] != -1) continue;
		build(y, cent, level + 1);
	}
}

void update(int x) {
	int y = x;
	int level = lvl[x];
	while (level != -1) {
		// shortest distance from y to any red node
		// update using new node x and its distance to the centroid y
		best[y] = min(best[y], dist[x][level]);
		y = par[y];
		level--;
	}
}

ll query(int x) {
	ll res = INF;
	int y = x;
	int level = lvl[x];
	while (level != -1) {
		// shortest distance to any red node in centroid chain
		res = min(res, best[y] + dist[x][level]);
		y = par[y];
		level--;
	}
	return res;
}

memset(lvl, -1, sizeof(lvl));
fill(best, best+n, INF);
build(0, -1, 0);
update(0); // adding a node to be considered
query(y); // querying with all considered nodes