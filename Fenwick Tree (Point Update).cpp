int ls(int x){ return (x)&(-x);}

long long fenwick[n+1];

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
