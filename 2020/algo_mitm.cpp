//Example - Bobek
//Count number of subsets with sum <= m
o = n/2; t = n-o;
//Generate first half of subsets
for(int i = 0; i < (1 << o); i++){
	c = bitset<50>(i);
	for(int j = 0; j < o; j++){
		if(c.test(j)) s[i] += a[j];
	}
}
sort(s, s+(1 << o));
//Generate second half of subsets
for(int i = 0; i < (1 << t); i++){
	c = bitset<50>(i); sum = 0;
	for(int j = 0; j < t; j++){
		if(c.test(j)) sum += a[o+j];
	}
	ans += upper_bound(s, s+(1<<o), m-sum)-s;
}