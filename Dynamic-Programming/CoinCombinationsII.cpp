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
vector<ll> out(10e6 + 1);

void solve() {
    ll n, x; cin >> n >> x;
    vector<ll> coins(n);
    rep0(i, n) {
        cin >> coins[i];
    }
    out[0] = 1;
    sort(all(coins));
    for(ll c : coins) {
        for(ll atual = c; atual <= x; atual++) {
            out[atual] = (out[atual] + out[atual - c]) % MOD;
        }
    }
    cout << out[x] % MOD << endl;
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

