#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

const int MAX = 400000 + 5;

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
	vector<vector<int>> adj(n);
	vector<array<ll, 3>> points(n);

	for(int i = 0; i < n; i++) cin >> points[i][2];
	
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a  >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int t = 1;
	auto dfs = [&](auto&& self, int v, int p = -1) -> void {
		points[v][0] = t++;

		for(auto& viz : adj[v]) if(viz != p) {
			self(self, viz, v);
		}

		points[v][1] = t - 1;
	};

	dfs(dfs, 0);

	bit fenwick(n);

	for(int i = 0; i < n; i++) {
		fenwick.insert(points[i][0], points[i][2]);
		fenwick.insert(points[i][1] + 1, -points[i][2]);
	}

	for(int i = 0; i < q; i++) {
		int t; cin >> t;
		if(t == 1) {
			int v, x; cin >> v >> x; v--;
			int dif = x - points[v][2];
			fenwick.insert(points[v][0], dif);
			fenwick.insert(points[v][1] + 1, - dif);
			points[v][2] = x;
		} else {
			int v; cin >> v; v--;
			int x = points[v][0], y = points[v][1];

			cout << fenwick.query(x) << '\n';
		}
	}	
}

int main() {
    fastio;
    solve();
	return 0;
}

