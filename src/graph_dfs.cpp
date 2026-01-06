// For adjacency lists
void dfs(int x, int p) {
    for (int y : adj[x]) {
        if(y != p){
            dfs(y, x);
        }
    }
}