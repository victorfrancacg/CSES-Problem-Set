#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

struct bit {
	int n;
	vector<ll> a;

	bit(int n) : n(n), a(n + 1) {}

	void add(int pos, int x) {
		for(; pos <= n; pos += (pos & -pos)) a[pos] += x;
	}

	ll query(int pos) {
		ll ans = 0;
		for(; pos > 0; pos -= (pos & -pos)) ans += a[pos];
		return ans;
	}
};

void solve() {
	int n; cin >> n;

	vector<int> sup(n, 0), inf(n, 0);
	vector<pair<int, int>> rgs(n);

	set<int> xs, ys;
	for(int i = 0; i < n;i++) {
		int a, b; cin >> a >> b;
		rgs[i] = {a, b};
		xs.insert(a); ys.insert(b);
	}
	
	map<int, int> rnkx, rnky;

	int aux = 1;
	
	for(auto& x : xs) {
		rnkx[x] = aux;
		aux++;
	}

	aux = 1;
	for(auto& y : ys) {
		rnky[y] = aux;
		aux++;
	}

	for(auto& [x, y] : rgs) {
		x = rnkx[x], y = rnky[y];
	}

	vector<int> id(n, 0);
	iota(all(id), 0);

	auto comp = [&](int i, int j) -> bool {
		if(rgs[i].first < rgs[j].first) return true;

		if(rgs[i].first == rgs[j].first && rgs[i].second < rgs[j].second) return true;
	
		return false;
	};

	sort(all(id), comp);
	sort(all(rgs));
	
	bit fenwick(300000);

	for(int i = 0; i < n;) {
		int st = i;

		auto [x, y] = rgs[i];

		fenwick.add(y, 1);

		i++;
		while(i < n && rgs[i].first == x) {
			fenwick.add(rgs[i].second, 1);
			i++;
		}

		for(int j = st; j < i; j++) {
			int ret = fenwick.query(rgs[j].second - 1);
			inf[id[j]] = i - ret - 1;
		}
	}	

	bit fenwick2(300000);

	for(int i = n - 1; i >= 0;) {
		int st = i;
		auto [x, y] = rgs[i];

		fenwick2.add(y, 1);

		i--;
		while(i >= 0 && rgs[i].first == x) {
			fenwick2.add(rgs[i].second, 1);
			i--;
		}

		for(int j = st; j > i; j--) {
			sup[id[j]] = fenwick2.query(rgs[j].second) - 1;
		}
	}

	for(auto& x : sup) cout << x << " ";
	cout << '\n';
	for(auto& x : inf) cout << x << " ";
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

