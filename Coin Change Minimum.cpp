int coins[c], mins[v+1];
memset(mins, INT_MAX, sizeof(mins));
mins[0] = 0;
for(int i = 1; i <= v; i++){
  for(int j = 0; j < c j++){
    if(i >= coins[j] && mins[i - coins[j]] != INT_MAX){
      mins[i] = min(mins[i], mins[i - coins[j]] + 1);
    }
  }
}
//QUERY: mins[v];
