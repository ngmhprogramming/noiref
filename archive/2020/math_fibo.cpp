typedef pair<pi, pi> matrix;
matrix multiply(matrix x, matrix y, long long z){
    return matrix(
            pi((x.f.f*y.f.f+x.f.s*y.s.f)%z,
                (x.f.f*y.f.s+x.f.s*y.s.s)%z),
            pi((x.s.f*y.f.f+x.s.s*y.s.f)%z,
                (x.s.f*y.f.s+x.s.s*y.s.s)%z));
}
matrix square(matrix x, long long y){
    return multiply(x, x, y);
}
matrix power(matrix x, long long y, long long z){
    if(y == 1) return x;
    if(y % 2 == 0) return square(power(x, y/2, z), z);
    return multiply(x, square(power(x, y/2, z), z), z);
}
long long fibo(long long n, long long m){
    matrix x = matrix(pi(1, 1), pi(1, 0));
    return power(x, n, m).f.s;
}
