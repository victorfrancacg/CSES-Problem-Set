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
	int n, q; cin >> n >> q;

	vector anc(32, vector<int>(n+1, - 1));

	for(int i = 1; i <= n; i++) {
		int t; cin >> t;
		anc[0][i] = t;
	}

	for(int i = 1; i < 31; i++) for(int j = 1; j <= n; j++) anc[i][j] = anc[i-1][anc[i-1][j]];

	auto jump = [&](int v, int k) {
		for(int i = 30; i >= 0; i--) {
			int aux = 1 << i;
			if(aux <= k) {
				v = anc[i][v];
				k -= aux;
			}
		}

		return v;
	};

	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b;
		cout << jump(a, b) << '\n';
	}
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

