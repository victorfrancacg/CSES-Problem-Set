#include <bits/stdc++.h>
using namespace std;

// Type definitions
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

// Macros for loops
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pop pop_back
#define endl '\n'

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void solve() {
    int n; cin >> n;
    vi c(n); rep0(i, n) cin >> c[i];

    sort(all(c));

    set<int> nums;
    for(auto& x : c) {
        vi toadd;
        for(auto& antigo : nums) toadd.pb(antigo + x);
        rep0(i, toadd.size()) nums.insert(toadd[i]);
        nums.insert(x);
    }
    cout << nums.size() << endl;
    for(auto& x : nums) cout << x << " ";
    cout << endl;
}

int main() {
    fast_io();
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}

