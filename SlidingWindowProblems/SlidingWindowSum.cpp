#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

/*
	"It is tempting, if the only tool you have is a hammer, to treat everything as if it were a nail."
*/

void solve() {
	ll n, k; cin >> n >> k;
	vector<ll> nums(n);
	ll x, a, b, c; cin >> x >> a >> b >> c;
	nums[0] = x;
	for(int i = 1; i < n; i++) {
		nums[i] = (a * nums[i - 1] + b) % c;
	}

	int l = 0, r = 0;
	
	ll out = 0, p = 0;

	while(r < n) {
		while(r - l + 1 <= k) {p += nums[r]; r++;}

		out ^= p;

		p -= nums[l];
		l++;
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

