int ls(int x){ return (x)&(-x); }

void pu(int i, int v){
    for(; i <= n; i += ls(i)) fw[i] += v;
}
int pq(int i){
    int t = 0;
    for(; i; i -= ls(i)) t += fw[i];
    return t;
}
int rq(int s, int e){
    return pq(e)-pq(s-1);
}