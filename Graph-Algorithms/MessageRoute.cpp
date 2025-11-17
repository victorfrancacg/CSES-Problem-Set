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

void solve() {
    ll n, m; cin >> n >> m;
    vector<vll> adj(n + 1);
    vector<bool> visited(n + 1, false);
    vector<ll> dist(n + 1);
    
    rep0(i, m) {
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    
    vll parent(n  + 1);
 
    queue<ll> fila;
    fila.push(1);
    visited[1] = true;
    while(!fila.empty()) {
        ll v = fila.front();
        fila.pop();
        for(auto viz : adj[v]) {
            if(!visited[viz]) {
                fila.push(viz);
                parent[viz] = v;
                dist[viz] = dist[v] + 1;
                visited[viz] = true;
            }
        }
    }
 
    ll atual = n;
    vector<ll> out;
    out.pb(n);
    while(atual != 1) {
        if(parent[atual] == 0) {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        out.pb(parent[atual]);
        atual = parent[atual];
    }
 
    cout << dist[n] + 1 << endl;
    for(ll i = out.size() - 1; i >= 0; i--) {
        cout << out[i] << " ";
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

