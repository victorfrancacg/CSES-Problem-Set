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
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    int n, m; cin >> n >> m;
    vector<vi> adj(n + 1);
    vector<int> indeg(n + 1, 0); 
    
    rep0(i, m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        indeg[b]++;
    }
 
    queue<int> q;
 
    rep(i, 1, n + 1) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }
 
    vi out;
 
    while(!q.empty()) {
        int u = q.front(); q.pop();
        out.pb(u);
 
        for(int v : adj[u]) {
            indeg[v]--;
            if(indeg[v] == 0) {
                q.push(v);
            }
        }
    }
 
    if((int) out.size() != n) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        rep0(i, n) {
            cout << out[i] << " ";
        }
        cout << endl;
    }
 
 
 
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
 
