#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

const int MAX = 100001;
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

	for(int i = 0; i < m ;i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
	}		

	tarjan(n);

	set<int> comps;

	for(int i = 0; i < n; i++) {
		comps.insert(comp[i]);
	}

	cout << comps.size() << '\n';

	map<int, int> rnk;

	int aux = 1;

	for(auto& c : comps) {rnk[c] = aux; aux++;}

	for(int i = 0; i < n; i++) {
		cout << rnk[comp[i]] << " ";
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

