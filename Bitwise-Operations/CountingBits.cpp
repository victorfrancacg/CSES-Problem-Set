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
	ll n; cin >> n;

	ll MAX = 1LL << 60, aux, out = 0LL;

	for(ll f = 2LL; f <= MAX; f <<= 1) {
		aux = n;
		aux++;

		if(f >= 2 * aux) continue;

		out += (aux / f) * (f / 2LL);
		aux = aux % f;
		aux -= f / 2;
		out += max(0LL, aux);
	}

	cout << out << '\n';
}

int main() {
    fastio;
    int t = 1;
  //  cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

