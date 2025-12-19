int dfs(int node){
    int size = 1, max_c = 0;
    for(auto it:adj[node]){
        if(it.s != par[node]){
            par[it.s] = node; dep[it.s] = dep[node]+1;
            int c_size = dfs(it.s);
            size += c_size;
            if(c_size > max_c){ max_c = c_size; heav[node] = it.s; }
        }
    }
    return size;
}
void decomp(int node, int hea){
    head[node] = hea; pos[node] = c_pos++;
    if(heav[node] != -1) decomp(heav[node], hea);
    for(auto it:adj[node]){
        if(it.s == par[node]) continue;
        if(it.s != heav[node]) decomp(it.s, it.s);
        root->update(pos[it.s], it.f);
    }
}
int query(int a, int b){
    int res = 0;
    for(; head[a] != head[b]; b = par[head[b]]){
        if(dep[head[a]] > dep[head[b]]) swap(a, b);
        res = max(res, root->query(pos[head[b]], pos[b]));
    }
    if(dep[a] > dep[b]) swap(a, b);
    res = max(res, root->query(pos[a]+1, pos[b]));
    return res;
}
dfs(0);
decomp(0, 0);
