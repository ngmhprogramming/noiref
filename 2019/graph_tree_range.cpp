int dfs(int x, int par){
    c++;
    pre[x] = c;
    for(auto it:adj[x]){
        if(it != par) rig[pre[x]] = max(rig[pre[x]], dfs(it, x));
    }
    if(rig[pre[x]] == 0) rig[pre[x]] = pre[x];
    return rig[pre[x]];
}
// node -> pre[x]
// children -> pre[x]+1, rig[pre[x]]
