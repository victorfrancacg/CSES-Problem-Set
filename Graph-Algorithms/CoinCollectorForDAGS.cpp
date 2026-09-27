#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpii vector<pii>
#define vpll vector<pll>

#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb push_back
#define mp make_pair
#define fi first
#define se second

#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

void solve() {
	/*
		Proper topology with DP is sufficient in the easy case that the graph is a DAG.
		How to proceed in a non-DAG graph?
		To deal with cycles, I can model it like SCC's (Strongly Connected Components). If I have a SCC in my graph, it is guaranteed that I can get all the coins in this SCC
		(summation of all vertices contained). So, I have to condensate the graph, switching SCC's by Super Nodes, representing the sum of coins in this SCC.

		Tarjan?
	*/

	int n, m; cin >> n >> m;

	vector<vector<int>> adj(n);
	vector<vector<int>> inv(n);
	vector<int> indeg(n);
	vector<int> a(n);

	for(int i =0 ; i < n; i++) {
		int v; cin >> v;
		a[i] = v;
	}

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		a--; b--;

		adj[a].push_back(b);
		inv[b].push_back(a);
		indeg[b]++;
	}

	queue<int> f;
	vector<ll> dp(n);

	for(int i = 0; i < n; i++) {
		if(indeg[i] == 0) {
			f.push(i);
		}
	}

	while(!f.empty()) {
		auto v = f.front(); f.pop();
		ll best = 0LL;

		for(auto& anc : inv[v]) {
			best = max(best, dp[anc]);
		}

		dp[v] = best + a[v];
	
		for(auto& viz : adj[v]) {
			indeg[viz]--;
			if(indeg[viz] == 0) {
				f.push(viz);
			}
		}
	}

	ll out = 0;
	for(int i = 0; i < n; i++) {
			out = max(out, dp[i]);
	}

	cout << out << '\n';
}

int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

