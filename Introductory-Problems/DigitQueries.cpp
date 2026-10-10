#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

void solve() {
	int q; cin >> q;
	for(int i=  0; i< q; i++) {
		ll x; cin >> x;

		ll acc = 0;
		for(ll faixa = 9, dig = 1; faixa <= 2 * 1e18; faixa *= 10, dig++) {
			if(x >= faixa * dig) {
				x -= faixa * dig;
				acc += faixa;
			} else {
				ll number = acc + (x / dig);
				if(x % dig) number++;

				int pos = dig - (x % dig);
				pos %= dig;
				while(pos--) {
					number /= 10;
				}
				
				cout << number % 10 << '\n';
				break;
			}
		}
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

