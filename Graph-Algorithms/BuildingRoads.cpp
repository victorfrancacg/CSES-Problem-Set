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

vector<vll> adj;
vector<bool> visited;

void dfs(ll alvo) {
    visited[alvo] = true;
    for(ll vizinho : adj[alvo]) {
        if(!visited[vizinho]) {
            dfs(vizinho);
        }
    }
}

void solve() {

    ll n, m; cin >> n >> m;
    
    adj.assign(n + 1, vll());
    visited.assign(n + 1, false);    

    rep0(i, m) {
        ll x, y; cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }

    vll abstracaoComponentes;

    for(ll i = 1; i <= n; i++) {
        if(!visited[i]) {
            abstracaoComponentes.pb(i);
            dfs(i);
        }
    }

    cout << abstracaoComponentes.size() - 1 << endl;
    rep0(i, abstracaoComponentes.size() - 1) {
        cout << abstracaoComponentes[i] << " " << abstracaoComponentes[i + 1] << endl;
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

