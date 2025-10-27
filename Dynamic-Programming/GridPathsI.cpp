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
    ll n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    rep0(i, n) {
        string s; cin >> s;
        rep0(j, n) {
            grid[i][j] = s[j];
        }
    }
    vector<vector<ll>> out(n, vector<ll>(n));
    if(grid[0][0] != '*') {
        out[0][0] = 1;
    }
    rep0(i, n) {
        rep0(j, n) {
            if(i == 0 && j == 0) {
                continue;
            }
            if(grid[i][j] == '*') {
                continue;
            }
            if(i - 1 >= 0 && grid[i - 1][j] != '*') {
                out[i][j] = (out[i][j] + out[i - 1][j]) % MOD;
            }
            if(j - 1 >= 0 && grid[i][j - 1] != '*') {
                out[i][j] = (out[i][j] + out[i][j - 1]) % MOD;
            }
        }
    }

    /**
    rep0(i, n) {
        rep0(j, n) {
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
    **/

    cout << out[n - 1][n - 1] % MOD << endl;
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

