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
#define mp make_pair
 
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>> 

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    ll n, m; cin >> n >> m;
    vector<vpll> adj(n + 1);
    vector<vll> inv(n + 1);
    rep0(i, m) {
        ll a, b, w; cin >> a >> b >> w;
        adj[a].pb(mp(b, w));
        inv[b].pb(a);
    }
 
    //adicionar, aqui, uma dp de se é possível chegar em N a partir do vértice i, for each 1 <= i <= N
    vector<bool> dpp(n + 1, 0);
    ll atual = n;
    queue<ll> back; back.push(atual); dpp[atual] = 1;
 
    while(!back.empty()) {
        auto v = back.front(); back.pop();
 
        for(auto& viz : inv[v]) {
            if(!dpp[viz]) {dpp[viz] = 1; back.push(viz);}
        }
    }
 
    //
    vll dp(n + 1, LLONG_MIN);
 
    dp[1] = 0;
 
    queue<ll> fila; fila.push(1);
 
    vll f(n + 1, 0); 

    while(!fila.empty()) {
        auto vv = fila.front(); fila.pop();
        
        if(!dpp[vv]) continue;

        for(auto& [ch, va] : adj[vv]) {
            if(dp[vv] + va > dp[ch]) {
                dp[ch] = dp[vv] + va;
                f[ch]++;
                if(f[ch] >= n && dpp[ch]) {cout << -1 << endl; return;} 
                fila.push(ch);
            }
        }
    }
 
    cout << dp[n] << endl;
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

