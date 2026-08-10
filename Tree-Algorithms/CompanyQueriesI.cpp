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
    vector<vector<int>> adj, anc;
    vector<int> dep, in, out;
    int n, lg, t;
    lca(int n) : n(n), adj(n + 1), dep(n + 1), in(n + 1), out(n + 1) {
        lg = 32 - __builtin_clz(n);
        anc = vector<vector<int>>(n + 1, vector<int>(lg));
    }
    void add_edge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    void dfs(int v, int p = -1, int d = 1) {
        dep[v] = d;
        in[v] = t++;
        rep(i, 1, lg) anc[v][i] = anc[anc[v][i - 1]][i - 1];
        for (int ch : adj[v]) if (ch != p) {
            anc[ch][0] = v;
            dfs(ch, v, d + 1);
        }
        out[v] = t++;
    }
    bool is_anc(int a, int b){
        return (in[a] <= in[b]) && (out[a] >= out[b]);
    }
    int get_lca(int a, int b) {
        if(is_anc(a, b)) return a;
        if(is_anc(b, a)) return b;
        for (int i = lg - 1; i >= 0; i--) {
            if (!is_anc(anc[a][i], b) && in[anc[a][i]] != out[anc[a][i]]){
                a = anc[a][i];
            }
        }
        return anc[a][0];
    }
    int dist(int a, int b) {
        return dep[a] + dep[b] - 2 * dep[get_lca(a, b)];
    }
    int jump(int v, int k) {
        for (int i = lg - 1; i >= 0; i--) {
            if ((1 << i) <= k) {
                v = anc[v][i];
                k -= (1 << i);
            }
        }
        return v;
    }
};

void solve() {
	int n, q; cin >> n >> q;

    lca tree(n);

    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        tree.add_edge(x, i);
    }

    tree.dfs(1);

    for(int i = 0; i < q; i++) {
        int x, k; cin >> x >> k;
        int out = tree.jump(x, k);
        if(out == 0) out = -1;
        cout << out << '\n';
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

