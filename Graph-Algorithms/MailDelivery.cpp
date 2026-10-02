#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

const int MAX = 1e5;

struct edge {
	int to;
	int id;

	edge(int t, int i) : to(t), id(i) {}
};

vector<edge> g[MAX];
vector<int> ans;
vector<int> vis;
vector<int> seen;

/**
visito por vértice mas marco aresta visitada. Problema: grafo relógio com o vértice saturado no centro. No pior caso, expando ele n / 2 vezes e faço ele olhar para arestas inúteis n vezes ao invés de uma só
*/
void dfs(int v) {

	while(seen[v] < g[v].size()) {
		edge viz = g[v][seen[v]++];
		if(vis[viz.id]) continue;
		vis[viz.id] = 1;
		dfs(viz.to);
	}

	ans.push_back(v);

	return;
}

void solve() {
	int n, m; cin >> n >> m;
	vector<int> deg(n, 0);
	vis.assign(m, 0);
	seen.assign(n, 0);

	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		deg[a]++; deg[b]++;
		pair<int, int> x = {a, b};
		pair<int, int> y = {b, a};

		g[a].push_back(edge(b, i));
		g[b].push_back(edge(a, i));

	}

	bool ok = true;
	for(int i = 0; i < n; i++) {
		if(deg[i] % 2 == 1) {
			ok = false;
			break;
		}
	}

	if(!ok) {cout << "IMPOSSIBLE" << '\n'; return;}
	
	dfs(0);
	
	if((int)ans.size() != m + 1) {
		cout << "IMPOSSIBLE" << '\n';
		return;
	}

	for(auto& x : ans) cout << x + 1 << " ";
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

