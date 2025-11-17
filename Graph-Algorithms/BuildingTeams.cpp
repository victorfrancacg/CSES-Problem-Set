#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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
#define rep1(i, a) rep(i, 1, a + 1)
#define repr(i, a, b) for (int i = (b) - 1; i >= (a); i--)

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

string bfs(vector<vll> &adj, vi &color, ll v) {
    color[v] = 1;
    queue<ll> fila;
    fila.push(v);
    while(!fila.empty()) {
        ll atual = fila.front();
        fila.pop();
        for(auto viz : adj[atual]) {
            if(color[viz] == -1) {
                color[viz] = 1 - color[atual];
                fila.push(viz);
            } else if(color[viz] == color[atual]) {
                cout << "IMPOSSIBLE" << endl;
                return "error";
            }
        }
    }
    return "ok";
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vll> adj(n + 1);
    rep0(i, m) {
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    vector<int> color(n +1, -1);
    for(ll i = 1; i <= n; i++) {
        if(color[i] == -1) {
            string retorno = bfs(adj, color, i);
            if(retorno == "error") {
                return;
            }
        }
    }
    /**
    rep(i, 1, n + 1) {
        cout << color[i] << " ";
    }
    cout << endl;
    **/
    rep(i, 1, n + 1) {
        if(color[i] == 0) {
            cout << 2 << " ";
        } else {
            cout << 1 << " ";
        }
    }
    cout << endl;
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

