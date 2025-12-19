int dp[al+1][bl+1]; //some extra space
string a, b; //uses strings
int lcs(int al, int bl){
	if(al == 0 || bl == 0) return 0; //empty strings don't have common things
	if(dp[al][bl] != -1) return dp[al][bl]; //if precomputed
	dp[al][bl] = max(lcs(al-1, bl), lcs(al, bl-1)); //don't take last char of a, or don't take last char of b
	if(a[al-1] == b[bl-1]) dp[al][bl] = max(dp[al][bl], lcs(al-1, bl-1)+1); //if both ends match then check if not taking last char of a and b is better
	return dp[al][bl];
}
//QUERY: lcs(a.size(), b.size())
