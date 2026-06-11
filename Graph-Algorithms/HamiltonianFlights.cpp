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

void solve() {
    ll n, m; cin >> n >> m;

	vector<vll> dp((1 << n), vll(n, 0LL));

    vector<vll> origens(n);

    rep0(i, m) {
        ll a, b; cin >> a >> b; a--; b--;
        origens[b].pb(a);
    }


    //LSB será vtx 1;
    
    dp[1][0] = 1LL;

    for(ll i = 0; i < (1 << n); i++) {
        for(ll j = 0; j < n; j++) {

            if(!(i & 1) || !(i & (1 << j))) continue;

            ll maskSemVtx = i ^ (1 << j);

            for(auto viz : origens[j]) {
                dp[i][j] = (dp[i][j] + dp[maskSemVtx][viz]) % MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;
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


