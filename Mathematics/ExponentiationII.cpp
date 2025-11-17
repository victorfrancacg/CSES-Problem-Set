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

ll fast_pow(ll a, ll b, ll mod) {
    if(a == 0 && b == 0) {
        return 1;
    }
    ll out = 1;
    while(b > 0) {
        if(b & 1) out = (out * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return out;
}

void solve() {
    ll a, b, c; cin >> a >> b >> c;
    cout << fast_pow(a, fast_pow(b, c, MOD - 1), MOD) << endl;
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

