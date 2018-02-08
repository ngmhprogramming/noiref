int numbers[n+1][n+1], sums[n+1][n+1]; //y_coord, x_coord,  1-indexed
int query(int y1, int x1, int y2, int x2){ //start and end inclusive, 1-indexed
	return sums[y2][x2] - sums[y1-1][x2] - sums[y2][x1-1] + sums[y1-1][x1-1];
}
//int main()
for(int i = 1; i <= n; i++){ //precomputation
	for(int j = 1; j <= n; j++) sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + numbers[i][j];
}
//QUERY: query(top_left_y_coord, top_left_x_coord, bottom_right_y_coord, bottom_right_x_coord)
