typedef pair<int, int> pi;
typedef pair<pi, int> pii;

pii edges[e];
int rank[nodes], parent[nodes], maximum = -1;
//UFDS implementation
int root(int x){
  if(parent[x] == -1) return x;
  return parent[x] = root(parent[x]);
}

void connect(int x, int y){
  if(root(x) != root(y)){
    parent[root(x)] = y; 
  }
}
//sort in increasing order
bool cmp(pii x, pii y){
  return x.second < y.second;
}
memset(parent, -1, sizeof(parent)); //no parents yet
sort(edges, edges+e, cmp); //sort in increasing order
for(int i = 0; i < e; i++){
  connect(edges[i].first.first, edges[i].first.second); //add edge to connected list
  maximum = edges[i].second; //furthest weight so far, no need max() as it is already sorted
  if(root(s) == root(d)) break; //if our destination is connected
}
//QUERY: maximum
