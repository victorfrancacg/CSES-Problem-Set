#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

void solve() {
	int n; cin >> n;

	map<int, int> cnt;
	ll out = 0;
	vector<int> nums(n), pref(n);

	for(int i =0 ; i < n; i++) {
		cin >> nums[i];
		nums[i] = ((nums[i] % n) + n) % n;
	}


	for(int i = 0; i < n; i++) {
		pref[i] = nums[i];

		if(i - 1>=0) pref[i] += pref[i - 1];
		pref[i] %= n;

		if(pref[i] == 0) out++;
		out += cnt[pref[i]]++;
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

