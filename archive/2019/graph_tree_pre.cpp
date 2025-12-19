// UNTESTED
void dfs(int x, int par){
    c++;
    pre[x] = c;
    for(auto it:adj[x]){
        if(it != par) dfs(adj[it], x);
    }
}
