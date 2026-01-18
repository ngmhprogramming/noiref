for (int i = 0; i < N; i++) {
	long long v, w, k;
	cin >> v >> w >> k;
	if (w > S || k == 0) continue;
	k = min(k, S / w); // limit k
	ndp = dp;
	// process residue classes mod w by considering multiples
	for (int r = 0; r < w; r++) {
		// j = r + x * w, find range of x
		int X = (S - r) / w;
		deque<int> dq; // stores x indices, in decreasing values of dp[r+x*w] - v*x

		auto val = [&](int x) -> long long {
			return dp[r + x * w] - v * x;
		};

		for (int x = 0; x <= X; x++) {
			// remove out of window indices , need (x - t) <= k => t >= x - k
			while (!dq.empty() && dq.front() < x - k) dq.pop_front();

			// push current x
			while (!dq.empty() && val(dq.back()) <= val(x)) dq.pop_back();
			dq.push_back(x);

			// best is at front of deque
			// ndp[r+x*w] = max_{t in [x-k, x]} dp[r+t*w] + (x-t)*v
			//            = v*x + max_{t} (dp[r+t*w] - v*t)
			long long best = val(dq.front()) + v * x;
			int j = r + x * w;
			if (best > ndp[j]) ndp[j] = best;
		}
	}
	dp.swap(ndp);
}