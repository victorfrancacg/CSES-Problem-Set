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

int dfs(int i, int & t) {
	int lo = id[i] = t++;
	s.push(i);

	vis[i] = 2;

	for(int j : g[i]) {
		if(!vis[j]) lo = min(lo, dfs(j, t));
		else if(vis[j] == 2) lo = min(lo, id[j]);
	}	

	if(lo == id[i]) while(1) {
		int u = s.top(); s.pop();

		vis[u] = 1, comp[u] = i;
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

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}

	tarjan(n);

	map<int, int> vtx;

	for(int i = 0; i < n; i++) {
		if(vtx.size() >= 2) break;
		vtx[comp[i]] = i;
	}

	if(vtx.size() == 1) {
		cout << "YES" << '\n';
	} else {
		auto it = vtx.begin(), it2 = prev(vtx.end());

		int a = (*it).second, b = (*it2).second;

		vector<bool> vis(n, 0);
		vis[a] = true;

		queue<int> f; f.push(a);

		while(!f.empty()) {
			auto v = f.front(); f.pop();

			for(auto& viz : g[v]) if(!vis[viz]) {
				vis[viz] = true;
				f.push(viz);
			}
		}
		
		cout << "NO" << '\n';
		if(vis[b]) {
			cout << b + 1 << " " << a + 1 << '\n';
		} else {
			cout << a + 1<< " " << b + 1 << '\n';
		}
	}
}

int main() {
    fastio;
    int t = 1;
   // cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

