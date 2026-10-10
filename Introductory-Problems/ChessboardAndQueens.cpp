#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

vector m(8, vector<char>(8));
int out = 0;

void chess(vector<pair<int, int>> used) {
	int i = used.size();
	
	for(int j = 0; j < 8; j++) {
		if(m[i][j] == '.') {
			bool ok = true;
			for(auto& [x, y] : used) {
				if(abs(x - i) == abs(y - j)) ok = false;
				if(x == i || y == j) ok = false;
			}

			if(ok) {
				vector aux = used;
				aux.push_back({i, j});
				if(aux.size() != 8) chess(aux);
				else out++;
			}
		}
	}
}

void solve() {
		for(int i = 0; i < 8; i++) {
			for(int j = 0; j < 8; j++) {
				cin >> m[i][j];
			}
		}

		vector<pair<int, int>> u = {};
		chess(u);

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

