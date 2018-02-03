vector<pi> adjlist[nodes]; //edge, distance
priority_queue<pi, vector<pi>, greater<pi> > pq; //decreasing order, distance, node
memset(distance, -1, sizeof(distance)); //not computed
  pq.push(pi(0, source)); //start from source
  distance[source] = 0;
  while(!pq.empty()){ //unprocessed edges
    pi f = pq.top(); pq.pop(); //current node and distance
    if(f.first != distance[f.second]) continue; //if node has been processed
    for(vector<pi>::iterator it = adjlist[f.second].begin(); it != adjlist[f.second].end(); it++){ //loop through adjacent nodes
      if(distance[(*it).first] == -1 || distance[(*it).first] > f.first + (*it).second){ //if distance has not been computed or distance is shorter
        distance[(*it).first] = f.first + (*it).second; //new distance 
        pq.push(pi(distance[(*it).first], (*it).first)); //insert new shortest distance to current node and current node
      }
    }
  }
//QUERY: distance[end]
