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
    vll nums(n + 1);
    vector<vll> dp(n + 1, vll(m + 1));
    rep(i, 1, n + 1) {
        cin >> nums[i];
    }
    if(nums[1] == 0) {
        rep(j, 1, m + 1) {
            dp[1][j] = 1;
        }
    } else {
        dp[1][nums[1]] = 1;
    }
    rep(i, 2, n + 1) {
        if(nums[i] == 0) {
            rep(j, 1, m + 1) {
                if(j < m) {
                    dp[i][j] = (dp[i - 1][j + 1] + dp[i][j]) % MOD;
                }       
                dp[i][j] = (dp[i - 1][j] + dp[i][j]) % MOD;
                dp[i][j] = (dp[i - 1][j - 1] + dp[i][j]) % MOD;
            }
        } else {
            if(nums[i] + 1 <= m) {
                dp[i][nums[i]]  = (dp[i - 1][nums[i] + 1] + dp[i][nums[i]]) % MOD;
            }
            dp[i][nums[i]] = (dp[i - 1][nums[i] - 1] + dp[i][nums[i]]) % MOD;
            dp[i][nums[i]] = (dp[i - 1][nums[i]] + dp[i][nums[i]]) % MOD;
        }
    }
    ll out = 0;
    rep(i, 1, m + 1) {
        out = (out + dp[n][i]) % MOD;
    }
    cout << out % MOD<< endl;
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

