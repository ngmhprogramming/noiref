int ls(int x){ return (x)&(-x); }

//PURQ Code (PU, PQ)

void ru(int s, int e, int v){
    pu(s, v);
    pu(e+1, -v);
}