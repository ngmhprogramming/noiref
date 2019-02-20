int powmod(int a, int b, int m) {
    int res = 1;
    while(b > 0) {
    if(b % 2 == 1) res = mulmod(res, a, m);
        a = mulmod(a, a, m);
        b /= 2;
    }
    return res % m;
}
