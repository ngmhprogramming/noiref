#include <bits/stdc++.h>
using namespace std;

/*
2D Static Sum
O(1) Range Query, O(N^2) Point Update
a & ss are 1-indexed
precomputation = ss[i-1][j]+ss[i][j-1]-ss[i-1][j-1]+a[i][j]
(x1, y1) to (x2, y2) inclusive = ss[x2][y2]-ss[x1-1][y2]-ss[x2][y1-1]+ss[x1-1][y1-1]
*/

long long r, c, q, x1, y1, x2, y2, a[1001][1001], ss[1001][1001];
int main(){
    cin >> r >> c;
    for(int i = 1; i <= r; i++){
	for(int j = 1; j <= c; j++) cin >> a[i][j];
    }
    for(int i = 1; i <= r; i++){
	for(int j = 1; j <= c; j++) ss[i][j] = ss[i-1][j]+ss[i][j-1]-ss[i-1][j-1]+a[i][j];
    }
    cin >> q;
    for(int i = 0; i < q; i++){
	cin >> x1 >> y1 >> x2 >> y2;
	cout << ss[x2][y2]-ss[x1-1][y2]-ss[x2][y1-1]+ss[x1-1][y1-1] << "\n";
    }
}

