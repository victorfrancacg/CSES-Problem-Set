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

void solve() {
	ll n, x; cin >> n >> x;
    vi nums(n, 0);
    for(int i = 0; i < n; i++) cin >> nums[i];

    int na = n / 2;
    int nb = n - na;

    vector<ll> sums;
    ll out = 0;
    for(int i = 0; i < (1 << na); i++) {
        int aux = 1, idx = 0;
        ll sum = 0;
        while(aux < (1 << na)) {
            if(aux & i) sum += nums[idx];
            aux <<=1;
            idx++;
        }

        if(sum == x) out++;
        else {
            sums.pb(sum);
        }
    }

    sort(sums.begin(), sums.end());
    reverse(nums.begin(), nums.end());

    for(int i = 0; i < (1 << nb); i++) {
        int aux = 1, idx = 0;
        ll sum = 0;
        while(aux < (1 << nb)) {
            if(aux & i) sum += nums[idx];
            aux <<=1;
            idx++;
        }
        
        if(sum == x) out++;
        else {
            ll find = x - sum;

            out += upper_bound(sums.begin(), sums.end(), find) - lower_bound(sums.begin(), sums.end(), find);
        }
    }

    cout << out << '\n';

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

