// Alternatively, find highest common powers for each factor
int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
