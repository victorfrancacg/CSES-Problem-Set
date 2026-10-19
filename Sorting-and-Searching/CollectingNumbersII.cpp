#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

void solve() {
	int n, q; cin >> n >> q;
	vector<int> idxs(n + 1), nums(n + 1);
	int last = 0;
	int out = 1;
	for(int i = 1; i <= n; i++) {
		int x; cin >> x;

		idxs[x] = i;
		nums[i] = x;
	}

	for(int i = 2; i <= n; i++) {
		if(idxs[i] < idxs[i - 1]) out++;
	}

	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		if(a > b) swap(b, a);
		int v1 = nums[a];
		int v2 = nums[b];
	
		if(v1 == v2 + 1) {
			out++;
		} else if(v1 == v2 - 1) {
			out--;
		}

		if(v1 - 1 >= 1) {
			int lowa = idxs[v1 - 1];
			if(lowa < a && lowa >= b) {
				out++;
			} else if(lowa > a && lowa <= b) {
				out--;
			}
		}

		if(v2 - 1 >= 1) {
			int lowb = idxs[v2 - 1];
			if(lowb < b && lowb >= a) {
				out++;
			} else if(lowb > b && lowb <= a) {
				out--;
			}
		}
		if(v1 + 1 <= n) {
			int hia = idxs[v1 + 1];
			if(hia < a && hia >= b) {
				out--;
			} else if(hia > a && hia <= b) {
				out++;
			}
		}
		if(v2 + 1 <= n) {
			int hib = idxs[v2 + 1];
			if(hib < b && hib >= a) {
				out--;
			} else if(hib > b && hib <= a) {
				out++;
			}
		}

		nums[a] = v2;
		nums[b] = v1;
		idxs[v1] = b;
		idxs[v2] = a;
		cout << out << '\n';
	}
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

