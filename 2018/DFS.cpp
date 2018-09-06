int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
void dfs(int x_coord, int y_coord){
  if(visited[x_coord][y_coord] == 1) return; //break condition
  visited[x_coord][y_coord] = 1; //mark as visited
  for(int i = 0; i < 4; i++){ //all directions
    int a = x_coord + dx[i]; //calculate new place to go
    int b = y_coord + dy[i];
    if(a < 0 || b < 0 || a >= h || b >= w || visited[a][b] == 1) continue; //do not go if out of bounds or visited
    dfs(a, b);
  }
}
