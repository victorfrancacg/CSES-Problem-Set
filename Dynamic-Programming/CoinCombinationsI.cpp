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
    ll n, x; cin >> n >> x;
    vll coins(n);
    vll out(x + 1);
    rep0(i, n) {
        ll c; cin >> c;
        coins[i] = c;
    }
    sort(all(coins));
    rep0(i, n) {
        if(coins[i] <= x) {
            out[coins[i]] = 1;
        }
    }
    for(ll i = 1; i <= x; i++) {
        ll novo = 0;
        for(ll m : coins) {
            if(i - m >= 1) {
                novo += out[i - m];
            }
        }
        out[i] = (novo + out[i]) % MOD;
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

