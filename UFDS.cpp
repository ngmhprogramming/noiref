int rank[nodes], parent[nodes];
memset(parent, -1, sizeof(parent);
int root(int x){
	if(parent[x] == -1) return x; //if we reached the top
	//return root(parent[x]); //travel up the tree
	return parent[x] = root(parent[x]); //include path compression by bringing nodes further up the tree
}
void connect(int x, int y){
	if(root(x) != root(y)){
		//parent[root(x)] = y //change x to child of y
		if(power[root(x)]>power[root(y)]){ //if x is higher
			parent[root(y)] = root(x); //y is the child
		} else if(power[root(x)]<power[root(y)]){
			parent[root(x)] = root(y); //x is the child
		} else {
			parent[root(y)] = root(x); //y is the child
			rank[root(x)]++; //x is pushed higher
		}
	}
}
//QUERY: root(node)
//QUERY: connect(node_x, node_y)
