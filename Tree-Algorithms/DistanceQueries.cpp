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

const int MAX = 200000;

int d[MAX], p[MAX], pp[MAX];

void set_root(int i) {
    p[i] = pp[i] = i, d[i] = 0;
}

void add_leaf(int i, int u) {
    p[i] = u, d[i] = d[u] + 1;
    pp[i] = 2*d[pp[u]] == d[pp[pp[u]]]+d[u] ? pp[pp[u]] : u;
}

int kth(int i, int k) {
    int dd = max(0, d[i] - k);
    while(d[i] > dd) i = d[pp[i]] >= dd ? pp[i] : p[i];
    return i;
}

int lca(int a, int b) {
    if(d[a] < d[b]) swap(a, b);

    while(d[a] > d[b]) a = d[pp[a]] >= d[b] ? pp[a] : p[a];
    while(a != b) {
        if(pp[a] != pp[b]) a = pp[a], b = pp[b];
        else a = p[a], b = p[b];
    }

    return a;
}

int dist(int a, int b) {
    return d[a] + d[b] - 2 * d[lca(a, b)];
}

vector<int> g[MAX];

void build(int i, int pai = -1) {
    if(pai == -1) set_root(i);
    for(int j : g[i]) if(j != pai) {
        add_leaf(j, i);
        build(j, i);
    }
}

void solve() {
    int n, m; cin >> n >> m;
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        g[a].pb(b); g[b].pb(a);
    }

    build(0);

    int l,r;
    for(int i = 0; i < m; i++) {
        cin >> l >> r;
        l--; r--;
        cout << dist(l, r) << '\n'; 
    }
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

