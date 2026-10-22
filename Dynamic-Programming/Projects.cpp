#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

/*
	"It is tempting, if the only tool you have is a hammer, to treat everything as if it were a nail."
*/

void solve() {
	int n; cin >> n;
	vector<array<ll, 3>> nums(n);
	for(int i = 0; i < n; i++) {
		int l, r, c; cin >> l >> r >> c;
		nums[i] = {r, l, c};
	}

	sort(all(nums));

	map<ll, ll> dp;

	ll out = 0;

	for(int i = 0; i < n; i++) {
		auto [r, l, c] = nums[i];

		auto &cur = dp[r];

		auto last = dp.lower_bound(r);
		if(last != dp.begin()) {
			last = prev(last);
			cur = max(cur, (*last).second);
		}
	
		ll factor = c;

		auto it = dp.lower_bound(l);
		if(it != dp.begin()) {
			it = prev(it);
			factor += (*it).second;
		}
		
		cur = max(cur, factor);
		out = max(out, cur);
	}
	
	cout << out << '\n';

}

int main() {
    fastio;
    int t = 1;
//    cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

