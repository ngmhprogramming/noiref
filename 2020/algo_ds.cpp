for(int i = 0; i < n; i++){
    cin >> a[i];
    b[i] = a[i];
}
sort(b, b+n);
for(int i = 0; i < n; i++){
    d = lower_bound(b, b+n, a[i])-b;
    a[i] = d+1;
}
