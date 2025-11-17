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

vll nums(1e6 + 1);

void count() {
    rep(i, 1, 1e6 + 1) {
        for(ll j = i; j <= 1e6 + 1; j += i) {
            nums[j]++;
        }
    }
}

void solve() {
    ll x; cin >> x;
    cout << nums[x] << endl;
}

int main() {
    fastio;
    int t;
    cin >> t;
    count();
    while(t--) {
	    solve();
    }

    return 0;
}

