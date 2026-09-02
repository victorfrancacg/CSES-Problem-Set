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

void solve() {
	int n; cin >> n;
    vector<vector<int>> adj(n + 1);
    for(int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].pb(b); adj[b].pb(a);
    }

    vector<int> cnt(n + 1, 0);
    vector<ll> dp(n + 1, 0LL);

    auto dfs = [&](auto&& dfs, int v, int p, int dist) {
        dp[1] += dist;
        if(adj[v].size() == 1 && p != -1) {
            cnt[v] = 1;
            return;
        } else {
            for(auto& viz : adj[v]) {
                if(viz == p) continue;

                dfs(dfs, viz, v, dist + 1);
                cnt[v] += cnt[viz];
            }
            
            cnt[v]++;
        }
    };

    dfs(dfs, 1, -1, 0);

    auto dfss = [&](auto&& dfss, int v, int p) {
        if(v != 1) {
            int dentro = cnt[v] - 1;
            int fora = n - cnt[v] - 1;
            dp[v] = dp[p] - dentro + fora;
        }

        if(adj[v].size() == 1 && p != -1) return;

        for(auto& viz : adj[v]) {
            if(viz == p) continue;

            dfss(dfss, viz, v);
        }
    };

    dfss(dfss, 1, -1);

    for(int i = 1; i <= n; i++) {
         cout << dp[i] << " ";
    }

    cout << '\n';
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

