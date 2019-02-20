int root(int x){
    if(p[x] == -1) return x;
    return p[x] = root(p[x]);
}
void connect(int x, int y){
    p[root(x)] = root(y);
}
