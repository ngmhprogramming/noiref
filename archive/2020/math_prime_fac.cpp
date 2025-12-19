while(x % 2 == 0){ cnt[2]++; x /= 2; }
for(int i = 3; i*i <= x+1; i += 2){
    while(x % i == 0){ cnt[i]++; x /= i; }
    if(x == 1) break;
}
if(x > 1) cnt[x]++;
