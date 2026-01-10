struct Query {
	int l, r, idx;
};

vector<ll> a(n);
int blockSize = sqrt(n) + 1;
ll sum = 0;

bool cmp(const Query &x, const Query &y) {
	int bx = x.l / blockSize;
	int by = y.l / blockSize;
	if (bx != by) return bx < by;
	return (bx & 1) ? (x.r < y.r) : (x.r > y.r);
}

// modify to insert idx
void plus(int idx) {
	sum += a[idx];
}

// modify to remove idx
void minus(int idx) {
	sum -= a[idx];
}

// make sure indexes are 0-indexed
vector<Query> queries(q);
sort(queries.begin(), queries.end(), cmp);
vector<ll> ans(q);
int curL = 0, curR = -1;
for (Query &cq : queries) {
	while (curL > cq.l) plus(--curL);
	while (curR < cq.r) plus(++curR);
	while (curL < cq.l) minus(curL++);
	while (curR > cq.r) minus(curR--);
	ans[cq.idx] = sum;
}