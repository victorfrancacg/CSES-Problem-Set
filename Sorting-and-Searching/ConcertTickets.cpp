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
    int n, m; cin >> n >> m;
    multiset<ll> nums;
    vll clients(m);
    rep0(i, n) {
        ll t; cin >> t;
        nums.insert(t);
    }
    rep0(i, m) {
        ll c; cin >> c;
        clients[i] = c;
    }
    rep0(i, m) {
        ll v = clients[i];
        auto it = nums.upper_bound(v);
        if(it == nums.begin()) {
            cout << -1 << endl;
        } else {
            --it;
            cout << *it << endl;
            nums.erase(it);
        }
    }
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

