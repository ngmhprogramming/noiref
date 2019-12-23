sort(edgs.begin(), edgs.end());
for(auto it:edgs){
    if(root(it.second.first) != root(it.second.second)){
        connect(it.second.first, it.second.second);
        cost += it.first;
    }
}
