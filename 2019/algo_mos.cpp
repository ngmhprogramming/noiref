//queries : index, left, right
//answers : index, answer

bool cmp(pii x, pii y){
    if(x.second.first/blk != y.second.first/blk){
        return x.second.first/blk < y.second.first/blk;
    }
    if(x.second.first/blk & 1){
        return x.second.second < y.second.second;
    }
    return x.second.second > y.second.second;
}

blk = sqrt(n);
sort(qs, qs+q, cmp);
for(int i = 0; i < q; i++){
    l = qs[i].second.first; r = qs[i].second.second;
    while(lft > l){
        //remove a[lft-1]
        lft--;
    }
    while(rgt <= r){
        //add a[rgt]
        rgt++;
    }
    while(lft < l){
        //add a[lft]
        lft++;
    }
    while(rgt > r+1){
        //remove a[rgt-1]
        rgt--;
    }
    ans[i] = pi(qs[i].first, cur);
}
sort(ans, ans+q);
