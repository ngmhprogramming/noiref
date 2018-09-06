#include <bits/stdc++.h>
using namespace std;

/*
1D Maxsum
O(N)
dp(i) = { dp(i-1)+a[i] dp(i-1) >= 0
	  a[i] dp(i-1) < 0 
	}
*/
long long n, maxsum, a[100000], dp[100000];
int main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    maxsum = dp[0] = a[0];
    for(int i = 1; i < n; i++){
	dp[i] = max(dp[i-1]+a[i], a[i]);
	maxsum = max(maxsum, dp[i]);
    }
    cout << maxsum;
}
