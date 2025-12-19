int query(int l, int r){
    r++;
    int p = 31-__builtin_clz(r-l);
    return __gcd(sp[p][l], sp[p][r-(1<<p)]);
}

h = floor(log2(n));
for(int i = 0; i < n; i++) sp[0][i] = a[i];
for(int i = 1; i <= h; i++){
    for(int j = 0; j+(1<<i) <= n; j++){
        sp[i][j] = __gcd(sp[i-1][j], sp[i-1][j+(1<<(i-1))]);
    }
}
