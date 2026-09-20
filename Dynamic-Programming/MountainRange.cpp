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
	stack<int> fw;
	stack<int> bw;

	int n; cin >> n;
	vector<pair<int, int>> a(n);
	vector<int> out(n, 1);
	vector<int> left(n, -1), right(n, -1);
	for(int i = 0; i < n ;i++) {
		int x; cin >> x;
		a[i] = {x, i};
	}

	for(int i = 0; i < n; i++) {
		while(fw.size() && a[fw.top()].first <= a[i].first) {
			fw.pop();
		}

		if(fw.size()) {
			left[i] = fw.top();	
		}

		fw.push(i);
	}

	for(int i = n - 1; i >= 0; i--) {
		while(bw.size() && a[bw.top()].first <= a[i].first) {
			bw.pop();
		}

		if(bw.size()) {
			right[i] = bw.top();
		}

		bw.push(i);
	}

	sort(all(a));

	for(int i = 0; i < n; i++) {
		auto [v, idx] = a[i];
		
//		cout << idx << " " << left[idx] << " " << right[idx] << '\n';
		if(left[idx] != -1) {
			out[left[idx]] = max(out[left[idx]], out[idx] + 1);
		}
		if(right[idx] != -1) {
			out[right[idx]] = max(out[right[idx]], out[idx] + 1);
		}
/**
		for(int i = 0; i < n; i++) {
			cout << out[i] << " ";
		}
		cout << '\n';
*/
	}	

	int ans = 1;
	for(auto& x : out) {
		ans = max(ans, x);
	}
	cout << ans << '\n';
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

