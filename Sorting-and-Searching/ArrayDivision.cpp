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
	ll n, k; cin >> n >> k;
    vll nums(n); rep0(i, n) cin >> nums[i];

    ll l = 1, r = 1e15;
    ll out = LLONG_MAX;

    while(l <= r) {
        ll mid = (l + r) / 2;

        ll aux = k, psum = 0;
        bool ok = true;
        
        aux--;
        rep0(i, n) {
            if(nums[i] > mid) {ok = false; break;}

            psum += nums[i];
            if(psum > mid && aux > 0) {
                aux--;
                psum = nums[i];
            } else if(psum > mid) {ok = false; break;}
        }

        if(ok) {
            out = min(out, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    cout << out << endl;
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

