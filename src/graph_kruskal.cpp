sort(edges.begin(), edges.end());
for (Edge e : edges) {
	if (root(e.u) != root(e.v)) {
		connect(e.u, e.v);
		cost += e.w;
	}
}