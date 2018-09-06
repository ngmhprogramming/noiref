#include <bits/stdc++.h>
using namespace std;

/*
UFDS (Union Find Disjoint Subsets)
O(N) Query, O(1) with path compression
O(N) Point Update, O(1) with path compression
*/
long long n, e, q, x, y, p[100000];
long long root(long long x){
    if(p[x] == x) return x;
    //return root(p[x]) //ordinary
    return p[x] = root(p[x]); //compress tree to height 2
}
void connect(long long x, long long y){
    if(root(x) != root(y)) p[root(x)] = root(y); //x (child), y (parent)
}
int main(){
    cin >> n >> e;
    for(int i = 0; i < n; i++) p[i] = i;
    for(int i = 0; i < e; i++){
	cin >> x >> y;
        connect(x, y);
    }
    cin >> q;
    for(int i = 0; i < q; i++){
	cin >> x >> y;
        if(root(x) == root(y)) cout << "CONNECTED\n";
	else cout << "DISJOINT\n";
    }	
}
