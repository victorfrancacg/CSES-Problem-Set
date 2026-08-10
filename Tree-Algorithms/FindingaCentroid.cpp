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
#define pb push_back
#define pop pop_back
#define endl '\n'
 
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
int n;
vector<vi> adj;
vi sz;
 
void dfs(int v, int pr) {
        sz[v] = 1;
 
        for(auto& viz : adj[v]) {
            if(viz == pr) continue;
 
            dfs(viz, v);
            sz[v] += sz[viz];
        }
}
 
int find(int v, int pr) {
    for(auto& viz : adj[v]) {
        if(viz == pr) continue;
 
        if(sz[viz] > n / 2) return (find(viz, v));
    }
 
    return v;
}
 
void solve() {
    cin >> n;
    
    adj.assign(n + 1, {});
    rep0(i, n -1) {
         int a, b; cin >> a >> b;
         adj[a].pb(b); adj[b].pb(a);
    }
    
    sz.assign(n + 1, 0);
 
    dfs(1, -1);
 
    cout << find(1, -1) << endl;
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
