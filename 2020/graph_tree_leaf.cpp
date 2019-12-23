for(int i = 1; i <= n; i++){
    if(adj[i].size() == 1) leafs.push(i);
}
while(!leafs.empty()){
    u = leafs.front(); leafs.pop();
    t = adj[u][0];
    adj[t].erase(find(adj[t].begin(), adj[t].end(), u));
    if(adj[t].size() == 1) leafs.push(t);
    adj[u].erase(find(adj[u].begin(), adj[u].end(), t));
}
