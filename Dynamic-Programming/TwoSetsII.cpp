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

ll fast_pow(ll a, ll b) {
    a %= MOD;

    ll res = 1;

    while(b > 0) {
        if(b & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

ll inverso(ll a) {
    return fast_pow(a, MOD - 2);
}

void solve() {
    int n, sum; cin >> n;
    sum = (n * (n + 1)) / 2;

    if(n <= 2 || sum % 2 == 1) {
        cout << 0 << endl; return;
    }
    
    sum /= 2;
    vll dp(sum + 1, 0);

    for(int i = 1; i <= n; i++) {
        for(int j = sum; j >= 1; j--) {
            if(dp[j] != 0) {
                if(j + i <= sum) dp[j + i] = (dp[j + i] + dp[j]) % MOD;
            } 
        }

        dp[i] = (dp[i] + 1LL) % MOD;
    }

    //divisao MODULARRRRRRRRRRRRRRRRRR
    cout << (dp[sum] * inverso(2LL))% MOD << endl;
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

