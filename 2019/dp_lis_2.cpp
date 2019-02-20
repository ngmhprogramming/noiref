for(int i = 0; i < n; i++){
    for(int j = 0; j < i; j++){
        if(a[j] < a[i]) lis[i] = max(lis[i], lis[j]);
    }
    lis[i]++;
    ans = max(ans, lis[i]);
}
