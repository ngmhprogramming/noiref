for (int i = 0; i < q; i++) {
	cin >> a >> b;
	// small to large merging
	if (s[a].size() > s[b].size()) swap(s[a], s[b]);
	for (int x : s[a]) s[b].insert(x);
	s[a].clear();
	cout << s[b].size() << "\n";
}