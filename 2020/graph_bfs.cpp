d[nx][ny] = 0;
q.push(pi(sx, sy));
while(!q.empty()){
    pi f = q.front(); q.pop();
    for(int i = 0; i < 4; i++){
        nx = f.first+dx[i];
        ny = f.second+dy[i];
        if(nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
        if(d[nx][ny] != -1) continue;
        d[nx][ny] = d[f.first][f.second]+1;
        q.push(pi(nx, ny));
    }
}
