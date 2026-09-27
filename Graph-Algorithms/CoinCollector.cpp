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

const int MAX = 100000;

vector<int> g[MAX];
stack<int> s;
int vis[MAX], comp[MAX];
int id[MAX];

int dfs(int i, int& t) {
	int lo = id[i] = t++;
	s.push(i);

	vis[i] = 2;

	for(int j : g[i]) {
		if(!vis[j]) lo = min(lo, dfs(j, t));
		else if(vis[j] == 2) lo = min(lo, id[j]);
	}

	if(lo == id[i]) while(1) {
		int u = s.top(); s.pop();

		vis[u] = 1; comp[u] = i;
		if(u == i) break;
	}

	return lo;
}

void tarjan(int n) {
	int t = 0;
	for(int i = 0; i < n; i++) vis[i] = 0;

	for(int i = 0; i < n; i++) if(!vis[i]) dfs(i, t);
}

void solve() {
	int n, m; cin >> n >> m;

	vector<int> a(n);
	for(int i = 0; i < n; i++) cin >> a[i];

	vector<pair<int, int>> edges(m);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		edges[i] = {a, b};
	}
	
	tarjan(n);

	vector<vector<int>> adj(n), inv(n);
	vector<int> indeg(n);

	for(int i = 0; i < m; i++) {
		int u = edges[i].first, v = edges[i].second;
		if(comp[u] == comp[v]) continue;

		adj[comp[u]].push_back(comp[v]);
		inv[comp[v]].push_back(comp[u]);
		indeg[comp[v]]++;
	}

	vector<ll> sum(n);

	for(int i = 0; i < n; i++) sum[comp[i]] += a[i];
	
	queue<int> f;

	for(int i = 0; i < n; i++) {
//		cout << comp[i] << " " << i << " " << indeg[i] <<  '\n';
		if(comp[i] == i && indeg[i] == 0) {
			f.push(i);
		}
	}

	vector<ll> dp(n);

	while(!f.empty()) {
		auto v = f.front(); f.pop();
		ll best = 0LL;

		for(auto& anc : inv[v]) {
			best = max(best, dp[anc]);
		}

		dp[v] = best + sum[v];

		for(auto& viz : adj[v]) {
			indeg[viz]--;
			if(indeg[viz] == 0) {
				f.push(viz);
			}
		}
	}

	ll out = 0LL;
	for(auto& x : dp) out = max(out, x);
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

