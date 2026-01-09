// Point Update, Range Sum Query

vector<ll> a(n);
int blockSize = sqrt(n) + 1;
vector<ll> blocks(blockSize, 0);
// precomputation
for (int i = 0; i < n; i++) {
	blocks[i / blockSize] += a[i];
}
// update
blocks[k/ blockSize] += u - a[k];
a[k] = u;
// query
ll sum = 0;
int s = l / blockSize;
int e = r / blockSize;
if (s == e) {
	for (int i = l; i <= r; i++) sum += a[i];
} else {
	for (int i = l; i < (s + 1) * blockSize; i++) sum += a[i];
	for (int b = s+1; b < e; b++) sum += blocks[b];
	for (int i = e * blockSize; i <= r; i++) sum += a[i];
}