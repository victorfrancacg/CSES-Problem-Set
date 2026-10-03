#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

const int inf = 1e9 + 1;
const int MAX = 2 * 1e5 + 5;

struct Bit {
	int n;
	vector<int> bit;
	Bit(int _n=0) : n(_n), bit(n + 1) {}

	void update(int i, int x) {
		for(i++; i <= n; i += i & -i) bit[i] += x;
	}

	int pref(int i) {
		int ans = 0;
		for(i ++ ; i; i -= i & -i) ans += bit[i];
		return ans;
	}
};

void solve() {
		int n; cin >> n;

		vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];

		Bit bit(MAX);

		for(int z = 0; z < n; z++) {
			int i; cin >> i; i--;

			int l = i, r = n - 1;

			int best = 1e9 / 3;
			while(l <= r) {
				int mid = (l + r) >> 1;
				int dead = bit.pref(mid);
				int alive = mid + 1 - dead;
				if(alive >= i + 1) {
					r = mid - 1;
					best = min(best, mid);
				} else if(alive < i + 1) {
					l = mid + 1;
				}
			}

			cout << a[best] << " ";
			bit.update(best, 1);
		}
		cout << '\n';
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

