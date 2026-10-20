#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

/*
	"It is tempting, if the only tool you have is a hammer, to treat everything as if it were a nail."
*/

struct bit {
	int n;
	vector<ll> a;

	bit(int n) : n(n), a(n + 1) {}

	void insert(int pos, ll v) {
		for(; pos <= n; pos += (pos & -pos)) a[pos] += v;
	}

	ll query(int pos) {
		ll ans = 0;
		for(; pos > 0; pos -= (pos & -pos)) ans += a[pos];
		return ans;
	}
};

void solve() {
	int n, q; cin >> n >> q;
	vector<vector<int>> adj(n + 1);
	bit fenwick(n);

	vector<int> in(n + 1, 0), out(n + 1, 0);

	vector<int> cost(n + 1, 0);

	for(int i = 1; i <= n; i++) cin >> cost[i];

	for(int i = 0; i < n - 1; i ++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int t = 1;

	auto dfs = [&](auto&& self, int v, int p = -1) -> void {
		in[v] = t++;
		for(auto& viz : adj[v]) if(viz != p) {
			self(self, viz, v);
		}
		out[v] = t - 1;
	};

	dfs(dfs, 1);

	for(int i = 1; i <= n; i++) {
		fenwick.insert(in[i], cost[i]);
	}

	for(int i = 0; i < q; i++) {
		int t; cin >> t;
		if(t == 1) {
			int x, v; cin >> x >> v;
			int time = in[x];
			fenwick.insert(time, v - cost[x]);
			cost[x] = v;
		} else {
			int x; cin >> x;
			int l = in[x], r = out[x];
			cout << fenwick.query(r) - fenwick.query(l - 1) << '\n';
		}
	}
}

int main() {
    fastio;
	solve();
	return 0;
}

