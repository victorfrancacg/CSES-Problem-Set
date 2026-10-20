#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

/*
	"It is tempting, if the only tool you have is a hammer, to treat everything as if it were a nail"
*/

const ll mod = 1e9 + 7;
ll out = 0LL;

ll fast_pow(ll a, ll b) {
	ll ans = 1LL;
	while(b) {
		if(b & 1) ans = (ans * a) % mod;
		a = (a * a) % mod;
		b >>= 1;
	}
	return ans;
}

int main() {
    fastio;
	ll n; cin >> n;

	for(ll l = 1; l <= n;) {
		ll q = n / l;
		ll r = n / q;
		ll factor = 1LL; 
		factor = (factor * ((r - l + 1) % mod)) % mod;
		factor = (factor * ((l + r) % mod)) % mod;
		factor = (factor * fast_pow(2, mod - 2)) % mod;
		factor = (factor * (q % mod)) % mod;
		out = (out + factor) % mod;
		l = r + 1;
	}

	cout << out % mod << '\n';

    return 0;
}

