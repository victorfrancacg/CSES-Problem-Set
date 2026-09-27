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

struct lca {
	int n, lg, t = 0;
	vector<vector<int>> adj, anc;
	vector<int> dep, in, out;

	lca(int n) : n(n), adj(n + 1), dep(n + 1), in(n + 1), out(n + 1) {
		lg = 32 - __builtin_clz(n);
		anc = vector(n + 1, vector<int>(lg));
	}

	void add_edge(int a, int b) {
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	void dfs(int v, int p = -1, int d = 1) {
		dep[v] = d;
		in[v] = t++;

		for(int i = 1; i < lg; i++) anc[v][i] = anc[anc[v][i-1]][i-1];

		for(auto& viz : adj[v]) if(viz != p) {
			anc[viz][0] = v;
			dfs(viz, v, d + 1);
		}

		out[v] = t++;
	}

	bool is_anc(int a, int b) {
		return (in[a] <= in[b]) && (out[a] >= out[b]);
	}

	int get_lca(int a, int b) {
		if(is_anc(a, b)) return a;
		if(is_anc(b, a)) return b;

		for(int i = lg - 1; i >= 0; i--) {
			if(!is_anc(anc[a][i], b) && in[anc[a][i]] != out[anc[a][i]]) {
				a = anc[a][i];
			}
		}

		return anc[a][0];
	}	

	int jump(int v, int k) {
		for(int i = lg - 1; i >= 0; i--) {
			if((1 << i) <= k) {
				v = anc[v][i];
				k -= (1 << i);
			}
		}
		return v;
	}

	int dist(int a, int b) {
		return dep[a] + dep[b] - 2 * dep[get_lca(a,b)];
	}
};

void solve() {
	int n, m; cin >> n >> m;
	
	lca tree(n);

	for(int i = 2; i <= n; i++) {
		int a, b; cin >> a >> b;
		tree.add_edge(a, b);
	}	

	tree.dfs(1);
	vector<int> out(n + 1, 0);

	/* trick do array de diferença, só que em árvore
		tá, mas como marcar de forma que não conte errado?
		pensa que, vindo das raízes, se eu encontro +1 eu estou em um novo caminho, e quando eu sei garantidamente que eu saio dele? 
		quando eu passo do LCA...
	*/


	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		int big = tree.get_lca(a, b);

		out[a]++;
		out[b]++;
		out[big]--;
		out[tree.anc[big][0]]--;
	}

	//vuu começar visitando os últimso que foram expandidos na DFS, ou seja, as folhas
	vector<int> visita(n);
	iota(all(visita), 1);
	sort(all(visita), [&](int a, int b) {return tree.in[a] > tree.in[b];});
	
	for(auto& v : visita) out[tree.anc[v][0]] += out[v];

	for(int i = 1;  i <= n; i++) cout << out[i] << " ";
	cout << '\n';
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

