int mulmod(int a, int b, int m) {
    int res = 0;
    while(b > 0) {
    if(b % 2 == 1) res = (res+a)%m;
        a = (a*2)%m;
        b /= 2;
    }
    return res % m;
}
