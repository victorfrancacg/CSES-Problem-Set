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

vector<vector<int>> adj;
vi dist;

void dfs(int v, int p, int d) {
    dist[v] = d;

    for(auto& viz : adj[v]) {
        if(viz == p) continue;

        dfs(viz, v, d + 1);
    }
}   

void solve() {
	int n; cin >> n;
    adj.assign(n + 1, {});
    dist.assign(n + 1, 0);

    for(int i = 0; i < n - 1; i ++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }
    
    dfs(1, -1, 0);

    int ext = -1, maxx = INT_MIN;
    for(int i = 1; i <= n; i++) {
        if(dist[i] > maxx) {
            maxx = dist[i];
            ext = i;
        }
    }

    dist.assign(n + 1, 0);
    dfs(ext, -1, 0);

    maxx = INT_MIN;

    for(int i = 1; i <= n; i++) {
        if(dist[i] > maxx) {
            maxx = dist[i];
        }
    }   
    cout << maxx << '\n';
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

