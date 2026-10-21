#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

/*
	"It is tempting, if the only tool you have is a hammer, to treat everything as if it were a nail."
*/

vector<int> id, art;
vector<vector<int>> adj;
vector<pair<int, int>> edges;

int dfs(int i, int& t, int p = -1) {
	int lo = id[i] = t++;

	for(int j : adj[i]) if(j != p) {
		if(id[j] == -1) {
			int val = dfs(j, t, i);
			lo = min(lo, val);
			if(val >= id[i]) {
				art[i]++;
			}
		} else {
			lo = min(lo, id[j]);
		}	
	}
	
	if(p == -1 && art[i]) art[i]--;
	return lo;
}

void solve() {
	int n, m; cin >> n >> m;

	adj.assign(n, {});
	id.assign(n, -1);
	art.assign(n, 0);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}	

	int t = 0;
	dfs(0, t);
	int out = 0;
	for(int i = 0; i < n; i++) {
		if(art[i]) {
			out++;
		}
	}
	cout << out << '\n';
	for(int i = 0; i < n; i++) {
		if(art[i]) {
			cout << i + 1 << " ";
		}
	}
	cout << '\n';
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

