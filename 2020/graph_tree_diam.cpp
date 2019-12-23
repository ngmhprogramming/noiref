pi dfs(int node, int par, int dist){
    pi b = pi(node, dist);
    for(auto it:adj[node]){
        if(it.first != par){
            pi c = dfs(it.first, node,dist+it.second);
            if(c.second > b.second) b = c;
        }
    }
    return b;
}
f = dfs(0, -1, 0);
l = dfs(f.first, -1, 0);
// l.second
