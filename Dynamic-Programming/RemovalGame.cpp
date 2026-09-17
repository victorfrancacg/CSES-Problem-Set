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
	ll n; cin >> n;
	vll nums(n + 1, 0); for(int i = 1; i <= n; i++) cin >> nums[i];

	vector dp(n + 2, vector<ll>(n + 2, 1e17));

	
	bool p1 = (n % 2 ? 1 : 0);
	for(int i = 1; i <= n; i++) {
		if(p1) {
			dp[i][i] = nums[i];
		} else {
			dp[i][i] = 0;
		}	
	}

	p1 = !p1;
	for(int i = 2; i <= n; i++) {
		for(int l = 1; l <= n - i + 1; l++) {
			int r = l + i - 1;
			if(p1) {
				dp[l][r] = -1e17;
				if(l + 1 <= n) dp[l][r] = max(dp[l][r], dp[l+1][r] + nums[l]);
				if(r - 1 >= 1) dp[l][r] = max(dp[l][r], dp[l][r-1] + nums[r]);
			} else {
				dp[l][r] = 1e17;
				if(l + 1 <= n) dp[l][r] = min(dp[l][r], dp[l+1][r]);
				if(r - 1 >= 1) dp[l][r] = min(dp[l][r], dp[l][r-1]);
			}
		}

		p1 = !p1;
	}

	cout << dp[1][n] << '\n';
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

