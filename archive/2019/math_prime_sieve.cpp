memset(prime, 1, sizeof(prime));
prime[0] = prime[1] = 0;
for(int i = 2; i <= 1000000; i++){
    if(prime[i]){
        for(int j = 2; i*j <= 1000000; j++){
            prime[i*j] = 0;
        }
    }
}
