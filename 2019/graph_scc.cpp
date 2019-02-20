stack<int> s;
vector<int> cur, adj[100001];
set<int> adjscc[100001];
vector<vector<int> > comps;
void scc(int v){
    idxs[v] = idx;
    lowlink[v] = idx;
    idx++;
    s.push(v);
    ins[v] = 1;
    for(auto w:adj[v]){
        if(idxs[w] == -1){
            scc(w);
            lowlink[v] = min(lowlink[v], lowlink[w]);
        } else if(ins[w]){
            lowlink[v] = min(lowlink[v], idxs[w]);
        }
    }
    if(lowlink[v] == idxs[v]){
        cur.clear();
        w = 0;
        while(w != v){
            w = s.top(); s.pop();
            ins[w] = 0;
            cur.push_back(w);
        }
        comps.push_back(cur);
    }
}
idx = 1;
memset(idxs, -1, sizeof(idxs));
for(int i = 1; i <= n; i++){
    if(idxs[i] == -1) scc(i);
}
memset(com, -1, sizeof(com));
for(int i = 0; i < comps.size(); i++){
    for(auto it:comps[i]) com[it] = i;
}
for(int i = 1; i <= n; i++){
    for(auto it:adj[i]){
        if(com[i] != com[it]) adjscc[com[i]].insert(com[it]);
    }
}
