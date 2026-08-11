#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

void solve() {
	int n, m; cin >> n >> m;
    vector<int> s(n + 1), t(m + 1);

    for(int i = 1; i <= n; i++) {
        cin >> s[i];
    }

    for(int i = 1; i <= m; i++) {
        cin >> t[i];
    }

    vector dp(n + 1, vector<int>(m + 1, 0));

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i] == t[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    cout << dp[n][m] << '\n';

    int i = n, j = m;

    vi out;
    while(i >= 1 && j >= 1) {
        if(s[i] == t[j]) {out.pb(s[i]); i--; j--;}
        else {
            if(dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
    }

    reverse(out.begin(), out.end());

    for(int i = 0; i < out.size(); i++) cout << out[i] << " ";
    cout << '\n';
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

