int par(int x, int k){
    for(int i = 19; i >= 0; i--){
        if(k >= (1<<i)){
            if(x == -1) return x;
            x = p[x][i];
            k -= (1<<i);
        }
    }
    return x;
}

memset(p, -1, sizeof(p));
dfs(0);
for(int k = 1; k <= 19; k++){
    for(int i = 0; i < n; i++){
        if(p[i][k-1] != -1) p[i][k] = p[p[i][k-1]][k-1];
    }
}
