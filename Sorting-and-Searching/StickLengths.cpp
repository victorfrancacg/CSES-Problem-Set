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
    int n; cin >> n;
    ll out = 0;
    ll out2 = 0;
    vll nums(n);
    rep0(i, n) {
        cin >> nums[i];
    }
    sort(all(nums));
    ll x1 = -1, x2 = -1;
    if(n % 2) {
        x1 = n / 2;
        x1 = nums[x1];
    } else {
        x1 = (n / 2) - 1;
        x2 = n / 2;
        x1 = nums[x1];
        x2 = nums[x2];
    }
    

    rep0(i, n) {
        if(n % 2) {
            out += abs(nums[i] - x1);
        } else {
            out += abs(nums[i] - x1);
            out2 += abs(nums[i] - x2);
        }
    }

    if(n % 2 == 0) {
        cout << min(out, out2) << endl;
    } else {
        cout << out << endl;
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

