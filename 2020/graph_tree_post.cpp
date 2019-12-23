// UNTESTED
void dfs(int x, int par){
    c++;
    for(auto it:adj[x]){
        if(it != par) dfs(adj[it], x);
    }
    post[x] = c;
}

