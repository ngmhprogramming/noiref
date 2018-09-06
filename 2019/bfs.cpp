#include <bits/stdc++.h>
using namespace std;

/*
BFS
O(N^2)
4 Direction: dx[]={0, 0, -1, 1}, dy[]={-1, 1, 0, 0}
8 Direction: dx[]={0, 0, -1, 1, -1, -1, 1, 1}, dy[]={-1, 1, 0, 0, 1, -1, -1, 1}
*/

typedef pair<int, int> pi;

long long r, c, x, y, nx, ny, dx[]={0, 0, -1, 1}, dy[]={-1, 1, 0, 0}, v[1000][1000];
char g[1000][1000];
queue<pi> q;
int main(){
    cin >> r >> c;
    for(int i = 0; i < r; i++){
	for(int j = 0; j < c; j++) cin >> g[i][j];
    }
    cin >> x >> y;
    q.push(pi(x, y));
    while(!q.empty()){
	pi f = q.front(); q.pop();
	v[f.first][f.second] = 1;
	for(int i = 0; i < 8; i++){
	    nx = f.first+dx[i];
	    ny = f.second+dy[i];
	    if(nx < 0 || ny < 0 || nx >= r || ny >= c) continue;
	    if(v[nx][ny] || g[nx][ny] != g[f.first][f.second]) continue;
	    q.push(pi(nx, ny));
	}
    }
    for(int i = 0; i < r; i++){
	for(int j = 0; j < c; j++){
	    if(v[i][j]) cout << "#";
	    else cout <<  g[i][j];
	}
	cout << "\n";
    }
}
