//Example - Supermarket
for(int i = 1; i <= n; i++){
    curw += w[i];
    //Remove the back until it is lower
    while(dq.size() > 0 && dq.back() > pd[i-1]) dq.pop_back();
    //Push current element
    dq.push_back(pd[i-1]);
    //Remove invalid items from the front
    while(curs < i && curw >= x){
        if(dq.front() == pd[curs-1]) dq.pop_front();
        curw -= w[curs];
        curs++;
    }
    //Take maximum range of front to back
    ans = max(ans, pd[i]-dq.front());
}

//Example - Rubies
for(int i = 1; i <= n; i++)
    ps[i] = ps[i-1]+c[i]-x*w[i];
    //Remove invalid items from the front
    while(dq.size() > 0 && (i-dq.front().S+1) > h) dq.pop_front();
    if(wait.size() > 0 && ((i-wait.front().S+1) >= l)){
        //Remove the back until it is lower
        while(dq.size() > 0 && dq.back().F > wait.front().F) dq.pop_back();	
        //Push current element
        dq.push_back(wait.front()); wait.pop_front();
    }
    //Take maximum range of front to back
    if(dq.size() > 0 && ((i-dq.front().S+1) >= l) && ps[i] >= dq.front().F) return true;
    wait.push_back(pi(ps[i-1], i));
    if(l == 1 && ps[i] >= ps[i-1]) return true;
}