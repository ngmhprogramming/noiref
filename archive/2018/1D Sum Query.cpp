int numbers[n], sums[n];
int query(int start, int end){ //start and end inclusive, 0-indexed
	return sums[end] - sums[start-1];
}
//int main()
sums[0] = numbers[0]; //base case, because it is 0-indexed
for(int i = 1; i < n; i++) sums[i] = sums[i-1]+numbers[i]; // precomputation
//QUERY: query(start(inclusive), end(inclusive))
