void dfs(int x, int p){
    for(auto it : adj[x]){
        if(it != p){
            par[it] = x;
            dep[it] = dep[x]+1;
            dist[it] = dist[x]+1;
            dfs(it, x);
        }
    }
}
