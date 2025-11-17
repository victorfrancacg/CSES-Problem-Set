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

struct Mat {
    ll a[2][2];
};

Mat exp(const Mat &a, const Mat &b) {
    Mat r;
    r.a[0][0] = ((a.a[0][0] * b.a[0][0]) % MOD + (a.a[0][1] * b.a[1][0]) % MOD) % MOD;
    r.a[0][1] = ((a.a[0][0] * b.a[0][1]) % MOD + (a.a[0][1] * b.a[1][1]) % MOD) % MOD;
    r.a[1][0] = ((a.a[1][0] * b.a[0][0]) % MOD + (a.a[1][1] * b.a[1][0]) % MOD) % MOD;
    r.a[1][1] = ((a.a[1][0] * b.a[0][1]) % MOD + (a.a[1][1] * b.a[1][1]) % MOD) % MOD;
    return r;
}

Mat fast_pow (Mat base, ll e) {
    Mat res = {1, 0, 0, 1};
    while(e) {
        if(e & 1) res = exp(res, base);
        base = exp(base, base);
        e >>= 1;
    }
    return res;
}

void solve() {
	//inicio
    ll n; cin >> n;
    if(n == 0) {
        cout << 0 << endl;
        return;
    }
    Mat in = {1, 1, 1, 0};
    Mat res = fast_pow(in, n - 1);
    cout << res.a[0][0] << endl;
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

