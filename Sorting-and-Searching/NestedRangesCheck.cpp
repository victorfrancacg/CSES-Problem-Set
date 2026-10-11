#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

void solve() {
	int n; cin >> n;
	map<int, int> cnty;
	int maxy = INT_MIN, miny = INT_MAX;

	vector<int> sup(n, 0), inf(n, 0);
	vector<pair<int, int>> rgs(n);

	for(int i = 0; i < n;i++) {
		int a, b; cin >> a >> b;
		rgs[i] = {a, b};
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
	
	for(int i = 0; i < n;) {
		int st = i;

		auto [x, y] = rgs[i];

		maxy = max(maxy, y);
		cnty[y]++;

		i++;
		while(i < n && rgs[i].first == x) {
			maxy = max(maxy, rgs[i].second);
			cnty[rgs[i].second]++;
			i++;
		}

		for(int j = st; j < i; j++) {
			if(maxy > rgs[j].second) {
				inf[id[j]] = 1;
			} else if(maxy == rgs[j].second) {
				if(cnty[maxy] >= 2) {
					inf[id[j]] =1;
				}
			}		
		}
	}	

	cnty.clear();

	for(int i = n - 1; i >= 0;) {
		int st = i;
		auto [x, y] = rgs[i];

		miny = min(miny, y);
		cnty[y]++;

		i--;
		while(i >= 0 && rgs[i].first == x) {
			miny = min(miny, rgs[i].second);
			cnty[rgs[i].second]++;
			i--;
		}

		for(int j = st; j > i; j--) {
			if(miny < rgs[j].second) {
				sup[id[j]] =1 ;
			} else if(miny == rgs[j].second) {
				if(cnty[miny] >= 2) sup[id[j]] = 1;
			}
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

