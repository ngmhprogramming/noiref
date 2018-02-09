int coins[n], ways[v];
ways[0] = 1;
for(int i = 0; i < c; i++){
  for(int j = 1; j <= v; j++){
    if(j >= coins[i]){
      ways[j] += ways[j-coins[i]];
    }
  }
}
//QUERY: ways[v]
