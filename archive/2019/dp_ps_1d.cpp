int query(int s, int e){
    return ps[e]-ps[s-1];
}

for(int i = 1; i <= n; i++) ps[i] = ps[i-1]+a[i];
