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
	int n, m; cin >> n >> m;

	vector<vector<int>> adj(n + 1);
	vector<int> dp(n + 1, 0), indeg(n + 1), parent(n + 1, -1);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		indeg[b]++;
	}

	dp[1] = 1;

	queue<int> f;
	for(int i = 1; i <= n; i++) {
		if(!indeg[i]) f.push(i);
	}

	while(!f.empty()) {
		auto v = f.front(); f.pop();

		for(auto& viz : adj[v]) {
			if(dp[v] > 0 && dp[v] + 1 > dp[viz]) {
				dp[viz] = dp[v] + 1;
				parent[viz] = v;
			}
			indeg[viz]--;
			if(indeg[viz] == 0) f.push(viz);
		}
	}

	if(dp[n] == 0) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	}

	cout << dp[n] << '\n';
	vector<int> out; out.push_back(n);
	int x = n;

	while(parent[x] != -1) {
		out.push_back(parent[x]);
		x = parent[x];
	}

	reverse(all(out));

	for(auto& ele : out) cout << ele << " ";
	cout << '\n';
}

int main() {
    fastio;
    int t = 1;
  //  cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

