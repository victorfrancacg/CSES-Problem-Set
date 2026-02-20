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
	int n; cin >> n;
    vector<bool> dp(n + 1, false);
    int k; cin >> k;
    set<int> nums;
    rep0(i, k) {
        int x; cin >> x;
        nums.insert(x);
    }
    for(auto& x : nums) {
        dp[x] = true;
    }
    dp[0] = false;
    rep(i, 1, n + 1) {
        for(auto& x : nums) {
            if(i - x < 0) continue;
            if(!dp[i - x]) {
                dp[i] = true;
                break;
            }
        }   
    }
    rep(i, 1, n + 1) {
        cout << (dp[i] ? "W" : "L");
    }
    cout << endl;
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

