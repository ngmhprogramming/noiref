priority_queue<pi, vector<pi>, greater<pi> > pq;
dist[s] = 0;
pq.push(pi(0, s));
while(!pq.empty()){
    pi f = pq.top(); pq.pop();
    for(auto it:adj[f.second]){
        if(dist[it.first] == -1 || dist[it.first] > f.first+it.second){
            dist[it.first] = f.first+it.second;
            pq.push(pi(dist[it.first], it.first));
        }
    }
}
