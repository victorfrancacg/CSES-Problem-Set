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
    ll n, x; cin >> n >> x;
    vll nums(n);
    rep0(i, n) {
        ll v; cin >> v;
        nums[i] = v;
    }
    multiset<pair<ll, ll>> numss;
    rep0(i, n) {
        numss.insert(mp(nums[i], i + 1));
    }
    for(auto& [ch, vl] : numss) {
        ll p1 = ch;
        auto it = numss.upper_bound({x - p1, LLONG_MAX});
        --it;
        if((*it).fi == x - p1 && (*it).se != vl) {
            cout << vl << " " << (*it).se << endl;
            return;
        }
    }
    cout << "IMPOSSIBLE" << endl;
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

