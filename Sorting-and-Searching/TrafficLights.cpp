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
    ll x, n; cin >> x >> n;
    vll nums(n);
    rep0(i, n) {
        ll k; cin >> k;
        nums[i] = k;
    }
    multiset<ll> difs;
    multiset<ll> lights;
    lights.insert(0LL);
    lights.insert(x);
    difs.insert(x);
    rep0(i, n) {
        ll toAdd = nums[i];
        auto it = lights.upper_bound(toAdd);
        auto it2 = prev(it);
        ll dif = *it - *it2;
        auto it3 = difs.lower_bound(dif);
        difs.erase(it3);
        lights.insert(toAdd);
        difs.insert(*it - toAdd);
        difs.insert(toAdd - *it2);
        ll out = *difs.rbegin();
        cout << out << " ";
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

