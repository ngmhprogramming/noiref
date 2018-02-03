int adjmatrix[nodes][nodes]; //build adjacency matrix first, usually with distances
//node order: kij, ij, ik, kj
for(int k = 0; k < nodes; k++){ //k
	for(int i = 0; i < nodes; i++){ //i
		for(int j = 0; j < nodes; j++){ //j
			adjmatrix[i][j] = max(adjmatrix[i][j], adjmatrix[i][k]+adjmatrix[k][j]); //shorten if it exists
		}
	}
}
//QUERY: adjmatrix[source][end]
