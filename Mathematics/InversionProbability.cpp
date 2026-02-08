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

long double round_half_6(long double x) {
    fesetround(FE_TONEAREST);

    long double scaled = x * 1000000.0L;
    long double rounded = nearbyintl(scaled);
    return rounded / 1000000.0L;
}

void solve() {
	int n; cin >> n;
    vi nums(n);
    rep0(i, n) {
        cin >> nums[i];
    }
    long double out = 0;
    rep0(i, n) {
        rep(j, i + 1, n) {
            int a = nums[i];
            int b = nums[j];
            long double expected = 0.000000;
            rep(k, 1, b + 1) {
                expected += (long double)(max(0, a - k));
            }
            expected /= (long double)(a * b);
            out += expected;
        }
    }
    out = round_half_6(out);
    cout << fixed << setprecision(6) << (double)out << endl;
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

