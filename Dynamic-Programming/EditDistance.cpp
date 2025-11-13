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
    string s1, s2; cin >> s1 >> s2;
    int n = s1.size(); int m = s2.size();
    vector<vi> dp(n + 1, vi(m + 1));

    rep0(i, n + 1) dp[i][0] = i;
    rep0(j, m + 1) dp[0][j] = j;

    rep1(i, n) {
        rep1(j, m) {
            if(s1[i - 1] == s2[j - 1]) 
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j - 1], dp[i-1][j-1]});
        }
    }

    cout << dp[n][m] << endl;
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

