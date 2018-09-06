#include <bits/stdc++.h>
using namespace std;

/*
1D Static Sum
O(1) Range Query, O(N) Point Update
a & ss are 1-indexed
precomputation = ss[i-1]+a[i]
s to e inclusive = ss[e]-ss[s-1]
*/

long long n, q, s, e, a[100001], ss[100001];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) ss[i] = ss[i-1]+a[i];
    cin >> q;
    for(int i = 0; i < q; i++){
	cin >> s >> e;
	cout << ss[e]-ss[s-1] << "\n";
    }
}
