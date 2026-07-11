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

vi out;
vector<vi> adj;

void dfs(int v, int p) {
    
    for(auto viz : adj[v]) {
        if(viz == p) continue;
        dfs(viz, v);
        out[v] += out[viz];
    }

    out[v]++;
    return;
}

void solve() {
	int n; cin >> n;
    out.assign(n + 1, 0);

    adj.assign(n + 1, {});

    rep(i, 2, n + 1) {
        int x; cin >> x;
        adj[x].pb(i); adj[i].pb(x);
    }

    dfs(1, -1);

    rep(i, 1, n + 1) {
        cout << out[i] - 1 << " ";
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

