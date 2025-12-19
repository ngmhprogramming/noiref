void dfs(int id){
	if(visited[id]) return;
	visited[id] = 1;
	for(auto it : adj[id]) dfs(it);
	ranking.push_back(id);
}