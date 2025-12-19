int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
queue<pi>> q; //y_coord, x_coord
visited[source] = 1; //mark as visited
q.push(pi(y_source, x_source); //start from source
while (!q.empty()){ // while still need to explore
	int current = q.front(); q.pop(); //current node
	for(int i = 0; i < 4; i++){ //all directions
    	int a = current.second + dx[i]; //calculate new place to go
    	int b = current.first + dy[i];
    	if(a < 0 || b < 0 || a >= h || b >= w || visited[a][b] == 1) continue; //do not go if out of bounds or visited
    	q.push(pi(b, a));
    	visited[a][b] = 1;
  	}
}
