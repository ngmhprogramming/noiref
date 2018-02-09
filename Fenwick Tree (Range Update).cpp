int ls(int x){ return (x)&(-x);}

long long fenwick1[n+1], fenwick2[n+1]; //remember that this is a 1-indexed tree, +1 for all the queries

void update(long long *tree, int index, long long value){
	for(; index <= n; index += ls(index)) tree[index] += value;
}

void range_update(int a, int b, long long value){
  update(fenwick1, a, value);
  update(fenwick1, b+1, -value);
  update(fenwick2, a, -value*(a-1));
  update(fenwick2, b+1, value*b);
}

long long query(long long *tree, int index){
	long long total = 0;
	for(; index; index -= ls(index)) total += tree[index];
	return total;
}

long long prefix_sum(int index){
  return query(fenwick1, index)*index + query(fenwick2, index);
}

long long range_query(int start, int end){
  return prefix_sum(end)-prefix_sum(start-1);
}
