//Query - 1-Indexed
int query(int s, int e){
    return ps[e]-ps[s-1];
}

//Precomputation
for(int i = 1; i <= n; i++) ps[i] = ps[i-1]+a[i];
