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
    ll n; cin >> n;
    vll out(n + 1);
    if(n <= 9) {
        cout << 1 << endl;
        return;
    }
    rep0(i, 10) {
        out[i] = 1;
    }
    rep(i, 10, n + 1) {
        ll aux = i;
        ll melhor = LLONG_MAX;
        while(aux != 0) {
            ll dig = aux % 10;
            aux /= 10;
            if(dig != 0) {
                melhor = min(melhor, out[i - dig] + 1);
            }
        }
        out[i] = melhor;
    }
    /*
    rep0(i, out.size()) {
        cout << out[i] << endl;
    }
    */
    cout << out[n] << endl;
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

