// Requires segment tree, supports path maximum queries

vector<pi> adj[MAXN];
int par[MAXN], dep[MAXN], heavy[MAXN], head[MAXN], pos[MAXN], cpos = 0;
// heavy: heavy child, head: start of chain, pos: position in segment tree

int dfs(int x, int p) {
	int sz = 1, maxc = 0;
	par[x] = p;
	for (pi y : adj[x]) {
		if (y.s != p) {
			dep[y.s] = dep[x] + 1;
			int csz = dfs(y.s, x);
			sz += csz;
			if (csz > maxc) {
				maxc = csz;
				heavy[x] = y.s;
			}
		}
	}
	return sz;
}

void decomp(int x, int h) {
	head[x] = h; pos[x] = cpos++;
	if (heavy[x] != -1) decomp(heavy[x], h);
	for (pi y : adj[x]) {
		if (y.s == par[x]) continue;
		if (y.s != heavy[x]) decomp(y.s, y.s);
		root->update(pos[y.s], y.f);
	}
}

int query(int a, int b) {
	int res = 0;
	for (; head[a] != head[b]; b = par[head[b]]) {
		// maintain b as deeper
		if (dep[head[a]] > dep[head[b]]) swap(a, b);
		res = max(res, root->query(pos[head[b]], pos[b]));
	}
	// a and b are now on the same chain
	if (dep[a] > dep[b]) swap(a, b);
	res = max(res, root->query(pos[a]+1, pos[b]));
	return res;
}

memset(heavy, -1, sizeof(heavy));
dep[0] = 0;
dfs(0, -1);
decomp(0, 0);