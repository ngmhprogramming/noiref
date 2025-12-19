void bridges(int x, int par){
    if(dep[x] != -1) return;
    dep[x] = low[x] = co++;
    int t = 0;
    for(auto it:adj[x]){
        if(it == par && t == 0){ t++; continue; }
        if(dep[it] != -1){
            if(low[it] > dep[x]) bgs.push_back(pi(x, it));
            low[x] = min(low[x], low[it]);
            continue;
        }
        bridges(it, x);
        if(low[it] > dep[x]) bgs.push_back(pi(x, it));
        low[x] = min(low[x], low[it]);
    }
}
for(int i = 1; i <= n; i++) bridges(i, 0);
