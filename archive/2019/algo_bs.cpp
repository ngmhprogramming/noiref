while(mini < maxi){
    medi = mini+(maxi-mini)/2;
    if(can(medi)) maxi = medi;
    else mini = medi+1;
}
