int lca(int x, int y){
    if(dep[x] < dep[y]) swap(x, y);
    for(int k = 19; k >= 0; k--){
        if(p[x][k] != -1 && dep[p[x][k]] >= dep[y]) x = p[x][k];
    }
    if(x == y) return x;
    for(int k = 19; k >= 0; k--){
        if(p[x][k] != p[y][k]){
            x = p[x][k];
            y = p[y][k];
        }
    }
    return p[x][0];
}
