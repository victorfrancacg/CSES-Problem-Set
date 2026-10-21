#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

/*
	"It is tempting, if the only tool you have is a hammer, to treat everything as if it were a nail."
*/

vector<int> id;
vector<vector<int>> adj;
vector<pair<int, int>> edges;

int dfs(int i, int& t, int p = -1) {
	int lo = id[i] = t++;

	for(int j : adj[i]) if(j != p) {
		if(id[j] == -1) {
			int val = dfs(j, t, i);
			lo = min(lo, val);
			if(val > id[i]) edges.push_back({i, j});
		} else {
			lo = min(lo, id[j]);
		}	
	}
	
	return lo;
}

void solve() {
	int n, m; cin >> n >> m;

	adj.assign(n, {});
	id.assign(n, -1);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	

	int t = 0;
	dfs(0, t);

	cout << edges.size() << '\n';
	for(auto& [v, u] : edges) cout << v + 1 << " " << u + 1 << '\n';
}

int main() {
    fastio;
    int t = 1;
//    cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

