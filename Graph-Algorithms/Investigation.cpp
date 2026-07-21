#include <bits/stdc++.h>
using namespace std;
 
// Type definitions
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
// Macros for loops
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define vpii vector<pii>
#define mp make_pair
#define vpll vector<pll>
 
const int MOD = 1e9 + 7;
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
vector<vpii> adj;
 
void solve() {
    int n, m; cin >> n >> m;
    adj.assign(n + 1, {});
 
    rep0(i, m) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].pb(mp(c, b));
    }
 
    //(1) dijkstra
 
    vll dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pll, vpll, greater<>> f; f.push(mp(0, 1));
 
    while(!f.empty()) {
        auto [w, v] = f.top(); f.pop();
 
        for(auto& [ww, vv] : adj[v]) {
            if(dist[v] + ww < dist[vv]) {
                dist[vv] = dist[v] + ww;
                f.push(mp(dist[vv], vv));
            }
        }
    }
 
    vll out;
    out.pb(dist[n]);
 
    //(2)ordenacao topologica para computar os caminhos distintos no grafo
 
    vector<vi> otimo(n + 1);
    vi dp(n + 1, 0);
    vi indeg(n + 1, 0);
    vector<vi> inv(n + 1);
    dp[1] = 1;
 
    for(int i = 1; i <= n; i++) {
        for(auto& [w, viz] : adj[i]) {
            if(dist[i] + w == dist[viz]) {
                otimo[i].pb(viz);
                indeg[viz]++;
                inv[viz].pb(i);
            }
        }
    }
 
    queue<int> fila; fila.push(1);
 
    vi maxx(n + 1, 0);
    vi minn(n + 1, INT_MAX);
    minn[1] = 0;
 
    while(!fila.empty()) {
        auto v = fila.front(); fila.pop();
 
        for(auto& pai : inv[v]) {
            dp[v] = (dp[v] + dp[pai]) % MOD;
            maxx[v] = max(maxx[v], maxx[pai] + 1);
            minn[v] = min(minn[v], minn[pai] + 1);
        }
 
        for(auto& viz : otimo[v]) {
            indeg[viz]--;
            if(indeg[viz] == 0) {
                fila.push(viz);
            }
        }
    }
    out.pb(dp[n]); out.pb(minn[n]); out.pb(maxx[n]);
    rep0(i, out.size()) {
        cout << out[i] << " ";
    }
    cout << endl;
}
 
int main() {
    fast_io();
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}
