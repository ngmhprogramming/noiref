void atp(int node, int depth){
    vi[node] = 1;
    dep[node] = depth;
    low[node] = depth;
    for(auto it:adj[node]){
        if(!vi[it]){
            par[it] = node;
            atp(it, depth+1);
            chi[node]++;
            if(low[it] >= dep[node]) atps[node]++;
            low[node] = min(low[node], low[it]);
        } else if(it != par[node]){
            low[node] = min(low[node], dep[it]);
        }
    }
}
atp(0, 0);
// root -> chi[i]
// other -> atps[i]+1