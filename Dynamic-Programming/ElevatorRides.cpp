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
	int n, x; cin >> n >> x;

    vi a(n);
    rep0(i, n) cin >> a[i];
    vpii dp((1 << n), {INT_MAX, INT_MAX});

    dp[0] = {0, 0};
    for(int i = 1; i < (1 << n); i++) {

        int f = 1, idx = 0;
        while(f < (1 << n)) {
            if(f & i) {
                int state = f ^ i;
                auto [srides, speso] = dp[state];
                if(speso + a[idx] <= x) speso += a[idx];
                else {srides += 1; speso = a[idx];}

                dp[i] = min(dp[i], mp(srides, speso));
            }
            idx++;
            f <<= 1;
        }
    }

    cout << dp[(1 << n) - 1].fi + 1 << endl;
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

