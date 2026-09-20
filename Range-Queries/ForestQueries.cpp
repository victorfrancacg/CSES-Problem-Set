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

int pref[1000][1000];

void solve() {
	int n, m; cin >> n >> m;

	char mat[n][n];

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) cin >> mat[i][j];
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(j - 1 >= 0) pref[i][j] += pref[i][j-1];
			if(i - 1 >= 0) pref[i][j] += pref[i-1][j];
			if(j - 1 >= 0 && i - 1 >= 0) pref[i][j] -= pref[i-1][j-1];
			if(mat[i][j] == '*') pref[i][j]++;
		}	
	}

	for(int i = 0; i < m; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		a--; b--; c--; d--;
		
		int out = pref[c][d];
		if(b -1 >= 0) out -= pref[c][b-1];
		if(a -1 >= 0) out -= pref[a-1][d];
		if(a-1>= 0 && b -1 >= 0) out += pref[a-1][b-1];
		cout << out << '\n';
	}
}

int main() {
    fastio;
    int t = 1;
   // cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

