for(int i = 0; i < n; i++){
    t = query(a[i]-1)+1;
    update(a[i], t);
    ans = max(ans, t);
}
