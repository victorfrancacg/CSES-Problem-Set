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

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
const int NN = 1e6 + 1, K = 2, P = uniform_int_distribution<int>(256, 1e9)(rng); // l > |sigma|, r < min(mod)
const ll MOD[] = {1000893493, 1013782387};
ll ph[NN][K], hh[NN][K], IT; // LEMBRAR DE CHAMAR pre()!!!!!!!!!!
void pre() { rep(i, 0, NN) rep(j, 0, K) ph[i][j] = i ? ph[i - 1][j] * P % MOD[j] : 1; }

struct hsh {
    int L;
    hsh() {}
    hsh(const string &s) {
        L = IT, IT += sz(s);
        rep(i, 0, sz(s)) rep(j, 0, K) {
            hh[L + i][j] = ((i > 0 ? hh[L + i - 1][j] * P : 0) + s[i]) % MOD[j];
        }
    }
    array<ll, K> operator()(int l, int r) {
        array<ll, K> ans;
        rep(j, 0, K) {
            ans[j] = hh[L + r][j] - (l > 0 ? hh[L + l - 1][j] * ph[r - l + 1][j] % MOD[j] : 0);
            if (ans[j] < 0) ans[j] += MOD[j];
        }
        // return ans[0] | (ans[1] << 31); // for K = 2
        return ans;
    }
};

void solve() {
    pre();
	string s, t; cin >> s >> t;
    int n = (int)s.size(), m = (int)t.size();
    
    if(m > n) {cout << 0 << '\n'; return;}

    hsh S(s), T(t);

    auto find = T(0, m - 1);
    int out = 0;
    
    for(int i = 0; i < n - m + 1; i++) {
            if(S(i, i + m - 1) == find) out++;
    }

    cout << out << '\n';
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

