#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

const int inf = 1e9;
const int MAX = 2 * 1e5 + 5;

namespace seg {
	int n, *v;

	pair<int, int> seg[4 * MAX];

	pair<int, int> build(int p = 1, int l = 0, int r = n - 1) {
		if(l == r) return seg[p] = {v[l], l};

		int m = (l + r) >> 1;

		return seg[p] = max(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
	}

	void build(int n2, int* v2) {
		n = n2;
		v = v2;
		build();
	}

	int query(int h, int p = 1, int l = 0, int r = n - 1) {
		if(seg[p].first < h) return inf;
		if(l == r) {
			return seg[p].second;
		}

		int m = (l + r) >> 1;
	
		int res = query(h, 2 * p, l, m);
		if(res == inf) return query(h, 2 * p + 1, m + 1, r);
		return res;
	}

	pair<int, int> update(int idx, int h, int p = 1, int l = 0, int r = n - 1) {
		if(l == r) return seg[p] = {seg[p].first - h, seg[p].second};

		int m = (l + r) >> 1;

		if(idx <= m) {
			update(idx, h, 2 * p, l, m);
		} else {
			update(idx, h, 2 * p + 1, m + 1, r);
		}

		return seg[p] = max(seg[2*p], seg[2*p+1]);
	}
};

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n); for(int i = 0; i < n; i++) cin >> a[i];

	seg::build(n, a.data());

	for(int i = 0; i < m; i++) {
		int h; cin >> h;

		int v = seg::query(h);
		if(v == inf) v = 0;
		else {
			seg::update(v++, h);
		}
		cout << v << " ";
	}
	cout << '\n';
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

