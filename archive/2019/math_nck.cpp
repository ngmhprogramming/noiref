if(k > n-k) k = n-k;
for(int i = 0; i < k; i++){
    ans *= (n-i);
    ans /= (i+1);
}
