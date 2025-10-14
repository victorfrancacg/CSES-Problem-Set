#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
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
#define rep1(i, a) rep(i, 1, a + 1)
#define repr(i, a, b) for (int i = (b) - 1; i >= (a); i--)

#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

void solve() {
    ll n; cin >> n;
    ll soma = (n + 1) * n / 2;
    if(soma % 2) {
        cout << "NO" << endl;
    } else {
        if(n % 2) {
            cout << n / 2 << endl;
            cout << n << " ";
            ll lim = n;
            ll i = 1;
            ll duplas = n / 2;
            while(i <= duplas / 2) {
                cout << i << " " << lim - i << " ";
                i++;
            }
            cout << endl;
            cout << n / 2 + 1 << endl;
            while(i <= duplas) {
                cout << i << " " << lim - i << " ";
                i++;
            }
            cout << endl;

        } else {
            cout << n / 2 << endl;
            ll lim = n + 1;
            ll i = 1;
            while(i <= n / 4) {
                cout << i << " " << lim - i << " ";
                i++;
            }
            cout << endl;
            cout << n / 2 << endl;
            while(i <= n / 2) {
                cout << i << " " << lim - i << " ";
                i++;
           }
           cout << endl;
        }
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

