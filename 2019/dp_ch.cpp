// dp(x) = max(dp(i)+f(p(x)-p(i)))
//       = max(dp(i)+a(p(x)-p(i))^2+b(p(x)-p(i))+c)
//       = max(dp(i)+ap(x)^2-2ap(x)p(i)+ap(i)^2+bp(x)-bp(i))+c
//       = max(dp(i)+ap(i)^2-bp(i)-2ap(x)p(i))+ap(x)^2+bp(x)+c
//       = max(c(i)+m(i)p(x))+v(x)
// c(i) = dp(i)+ap(i)^2-bp(i)
// m(i) = -2ap(i)
// v(x) = ap(x)^2+bp(x)+c
long long func(pi line, long long x){
    return line.first*x+line.second;
}
long double intersection(long long m1, long long c1, long long m2, long long c2){
    return (long double)(c2-c1)/(m1-m2);
}
long double intersect(pi x, pi y){
    return intersection(x.first, x.second, y.first, y.second);
}
long long query(long long x){
    while(hull.size() > 1){
        if(func(hull[0], x) < func(hull[1], x)){
            hull.pop_front();
        } else break;
    }
    return func(hull[0], x);
}
void insert(long long m, long long c){
    pi line = pi(m, c);
    while(hull.size() > 1){
        long long s = hull.size();
        if(intersect(hull[s-1], line) <= intersect(hull[s-2], line)){
            hull.pop_back();
        } else break;
    }
    hull.push_back(line);
}
insert(0, 0);
for(int i = 1; i <= n; i++){
    dp[i] = query(ps[i])+a*ps[i]*ps[i]+b*ps[i]+c;
    insert(-2*a*ps[i], dp[i]+a*ps[i]*ps[i]-b*ps[i]);
}
