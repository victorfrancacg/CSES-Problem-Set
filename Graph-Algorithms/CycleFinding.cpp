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
#define endl '\n'
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    ll n, m; cin >> n >> m;
    vector<vector<pll>> adj(n + 1);
    rep0(i, m) {
        ll a, b, w; cin >> a >> b >> w; w *= -1;
        adj[a].pb(mp(b, w));
    }
    vll count(n + 1, 0);
 
    vll dp(n + 1, 10LL * INT_MIN);
    vll parent(n + 1, -1);
 
    ll cycleSt = -1;
 
    for(ll st = 1; st <= n; st++) {
        if(count[st] > 0) continue;
 
        bool detected = false;
 
        queue<ll> nodes;
        nodes.push(st);
        dp[st] = 0;
 
        while(!nodes.empty()) {
            auto head = nodes.front(); nodes.pop();
 
            bool cycle = false;
            for(auto [viz, w] : adj[head]) {
                if(dp[head] + w > dp[viz]) {
                    dp[viz] = dp[head] + w;
                    parent[viz] = head;
                    if(count[viz] + 1 >= n) {cycle = true; cycleSt = viz; break;}
 
 
                    count[viz]++;
                    nodes.push(viz);
                }
            }
            if(cycle) {detected = true; break;}
        }
 
        if(detected) break;
    }
 
    if(cycleSt == -1) {cout << "NO" << endl; return;}
    cout << "YES" << endl;
 
    //dado que o ciclo existe, cycleSt == -1 OU qualquer parent pertencente ao
    //ciclo == -1 nao pode existir. Uma garantia por construção de que nao há
    //acesso inválido.
 
    vll out;
    
    ll x = cycleSt;
 
    //minha premissa era errada. retroceder n vezes garante que estou dentro do
    //ciclo pois, afinal, o grafo é direcionado.
    rep0(i, n) x = parent[x];
 
    out.pb(x);
    ll aux = parent[x];
    while(aux != x) {
        out.pb(aux);
        aux = parent[aux];
    }
    out.pb(x);
 
    reverse(all(out));
 
    rep0(i, out.size()) cout << out[i] << " ";
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
