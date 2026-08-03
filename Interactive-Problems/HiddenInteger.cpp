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

bool routine(ll y) {
    cout << "? " << y << endl;
    string ans; cin >> ans;
    return ans == "YES";
}

void solve() {
	    ll lo = 1, hi = 1e9;
    
        ll out = -1;
        while(lo <= hi) {
            ll mid = (lo + hi) / 2;
            if(routine(mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        cout << "! " << lo << "\n";
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

