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
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    ll n, x; cin >> n >> x;
    vll nums(n);
    rep0(i, n) {
        ll c; cin >> c;
        nums[i] = c;
    }
    vll out(x + 1, LLONG_MAX);
    sort(all(nums));
    rep0(i, n) {
        if(nums[i] <= x) {
            out[nums[i]] = 1;
        }
    }
    for(ll i = 1; i <= x; i++) {
        ll mini = LLONG_MAX;
        for(ll p : nums) {
            if(i - p >= 1 && out[i - p] != LLONG_MAX) {
                mini = min(out[i - p] + 1, mini);
            }
        }
        if(mini != LLONG_MAX) {
            out[i] = min(out[i], mini);
        }
    }
    if(out[x] == LLONG_MAX) {
        cout << -1 << endl;
        return;
    }
    cout << out[x] << endl;
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

