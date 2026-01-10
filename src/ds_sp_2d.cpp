int sp[MAXLOGN][MAXLOGM][MAXN][MAXM];

// Query - 0-indexed, inclusive
int query(int x1, int y1, int x2, int y2) {
	x2++; y2++;
	// 63 for long long
    int kx = 31 - __builtin_clz(x2 - x1);
    int ky = 31 - __builtin_clz(y2 - y1);
    int g1 = sp[kx][ky][x1][y1];
    int g2 = sp[kx][ky][x2 - (1 << kx)][y1];
    int g3 = sp[kx][ky][x1][y2 - (1 << ky)];
    int g4 = sp[kx][ky][x2 - (1 << kx)][y2 - (1 << ky)];
    return __gcd(__gcd(g1, g2), __gcd(g3, g4));
}

// Precomputation
// Build single elements
for (int i = 0; i < n; i++) {
	for (int j = 0; j < m; j++) {
		sp[0][0][i][j] = a[i][j];
	}
}
// Build along columns (k2)
for (int k2 = 1; (1 << k2) <= m; k2++) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j + (1 << k2) <= m; j++) {
			sp[0][k2][i][j] =
				__gcd(sp[0][k2-1][i][j],
					  sp[0][k2-1][i][j + (1 << (k2-1))]);
		}
	}
}
// Build along rows (k1)
for (int k1 = 1; (1 << k1) <= n; k1++) {
	for (int k2 = 0; (1 << k2) <= m; k2++) {
		for (int i = 0; i + (1 << k1) <= n; i++) {
			for (int j = 0; j + (1 << k2) <= m; j++) {
				sp[k1][k2][i][j] =
					__gcd(sp[k1-1][k2][i][j],
						  sp[k1-1][k2][i + (1 << (k1-1))][j]);
			}
		}
	}
}