long long n; cin >> n;
long long mini = 0, maxi = 1e6, medi;
while (mini < maxi) {
	medi = mini+(maxi-mini)/2;
	if (medi * medi * medi >= n) maxi = medi;
	else mini = medi+1;
}
cout << mini << "\n";