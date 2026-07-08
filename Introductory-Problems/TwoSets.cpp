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
	ll n; cin >> n;

    ll sum = ((n + 1) * n) / 2;

    if(sum % 2) {cout << "NO" << endl; return;}
    
    ll ref = n;
    vector<bool> nums(n + 1, 1);

    sum /= 2;

    while(ref > 0) {
        nums[ref] = 0;
        sum -= ref;
        if(sum < ref) {nums[sum] = 0; break;}
        ref--;
    }

    vi a, b;

    rep(i, 1, n + 1) {
        if(nums[i]) a.pb(i);
        else b.pb(i);
    }

    cout << "YES" << endl;
    cout << a.size() << endl;
    rep0(i, a.size()) cout << a[i] << " ";
    cout << endl;
    cout << b.size() << endl;
    rep0(i, b.size()) cout << b[i] << " ";
    cout << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}

