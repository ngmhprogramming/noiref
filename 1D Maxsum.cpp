int numbers[n], maxsum[n], ans;
ans = maxsum[0] = numbers[0]; //max of first number is the number itself
for(int i = 1; i < n; i++){
	maxsum[i] = max(maxsum[i-1]+numbers[i], numbers[i]); //take the number or take it by itself
	ans = max(ans, maxsum[i]);
}
//QUERY: ans
