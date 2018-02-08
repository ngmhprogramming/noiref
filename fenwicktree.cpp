#include <bits/stdc++.h>
using namespace std;

int ls(int x){ return (x)&(-x);}

int n, t, q, a, b, c;
long long fenwick[100001];

void point_update(int index, long long value){
	for(; index <= n; index += ls(index)) fenwick[index] += value;
}

long long point_query(int index){
	long long total = fenwick[index];
	index--;
	for(; index; index -= ls(index)) total -= fenwick[index];
	return total;
}

long long range_query(int start, int end){
	long long total = 0;
	start--;
	for(; end; end -= ls(end)) total += fenwick[end];
	for(; start; start -= ls(start)) total -= fenwick[start];
	return total;
}

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		cin >> t;
		point_update(i+1, t);
	}
	for(int i = 1; i <= n; i++) cout << fenwick[i] << " ";
	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		scanf("%d", &t);
		if(t == 0){
			scanf("%d %d", &a, &b);
			cout << range_query(a+1, b+1) << endl;
		} else {
			scanf("%d %d %d", &a, &b, &c);
			for(int j = a; j <= b; j++){
				point_update(j+1, c);
			}
		}
	}
}
