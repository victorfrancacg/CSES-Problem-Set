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

const ll MOD = 1e9 + 7;

vll dp;

void kahn(int n, vector<vi> & adj) {
    vi indegree(n + 1, 0);
    rep(i, 1, n + 1) {
        for(auto & v : adj[i]) {
            indegree[v]++;
        }
    }
    queue<int> fila;
    rep(i, 1, n + 1) {
        if(indegree[i] == 0) {
            fila.push(i);
        }
    }

    dp[1] = 1;
    
    while(!fila.empty()) {
        int topo = fila.front(); fila.pop();
        for(auto& viz : adj[topo]) {
            if(--indegree[viz] == 0) {
                fila.push(viz);
            }
            dp[viz] = (dp[viz] + dp[topo]) % MOD;
        }
    }
    return;
}

void solve() {
	int n; cin >> n; dp.resize(n + 1);
    int m; cin >> m; vector<vi> adj(n + 1);
    rep0(i, m) {
        int a, b; cin >> a >> b;
        adj[a].pb(b);
    }
    kahn(n, adj);
    cout << dp[n] << endl;
    
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

