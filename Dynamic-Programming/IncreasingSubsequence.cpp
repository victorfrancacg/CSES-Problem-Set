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
	int n; cin >> n;
    vector<int> nums(n + 1);
    for(int i = 1; i < n + 1; i++) {
        cin >> nums[i];
    }


    int out = -1e9;

    vector<int> lasts;

    for(int i = 1; i < n + 1; i ++) {
        int idx = lower_bound(lasts.begin(), lasts.end(), nums[i]) - lasts.begin();
        if(idx == lasts.size()) lasts.pb(nums[i]);
        else lasts[idx] = nums[i];
    }

    cout << lasts.size() << '\n';
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

