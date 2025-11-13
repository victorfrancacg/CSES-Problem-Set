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
    ll a, b; cin >> a >> b;
    vector<vll> dp(501, vll(501));
    rep(i, 1, 501) {
        rep(j, 1, 501) {
                ll v = LLONG_MAX;
                rep(k, 1, i) {
                    v = min(v, dp[i - k][j] + dp[k][j] + 1);
                }
                rep(l, 1, j) {
                    v = min(v, dp[i][j - l] + dp[i][l] + 1);
                }
                if(i != j) {
                    dp[i][j] = v;
                }
        }
    }
    cout << dp[a][b] << endl;
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

