ll dfs1(ll u, ll p, ll l){
	sub[u] = 1;
	for(auto it : adj[u]){
		if(ban[it.f] != -1) continue;
		if(it.f == p) continue;
		if(l) dst[it.f][l-1] = dst[u][l-1]+it.s;
		sub[u] += dfs1(it.f, u, l);
	}
	return sub[u];
}

ll dfs2(ll u, ll p, ll n){
	for(auto it : adj[u]){
		if(ban[it.f] != -1) continue;
		if(it.f != p && sub[it.f] > n/2){
			return dfs2(it.f, u, n);
		}
	}
	return u;
}

void build(ll u, ll p, ll l){
	ll n = dfs1(u, p, l);
	ll cent = dfs2(u, p, n);
	if(p == -1) p = cent;
	par[cent] = p;
	ban[cent] = l;
	for(auto it : adj[cent]){
		if(ban[it.f] != -1) continue;
		dst[it.f][l] = it.s;
		build(it.f, cent, l+1);
	}
}

void update(ll x){
	ll lvl = ban[x];
	ll y = x;
	while(lvl != -1){
		ans[y] = min(ans[y], dst[x][lvl]);
		st.push(y);
		y = par[y];
		lvl--;
	}
}

ll query(ll x){
	ll res = LLONG_MAX/3;
	ll lvl = ban[x];
	ll y = x;
	while(lvl != -1){
		res = min(res, ans[y]+dst[x][lvl]);
		y = par[y];
		lvl--;
	}
	return res;
}

//Initialisation
memset(ban, -1, sizeof(ban));
build(0, -1, 0);
for(ll i = 0; i < n; i++) ans[i] = LLONG_MAX/3;

//Adding a node to be considered
update(X);

//Querying with all considered nodes
query(Y);
while(!st.empty()){ ans[st.top()] = LLONG_MAX/3; st.pop(); }