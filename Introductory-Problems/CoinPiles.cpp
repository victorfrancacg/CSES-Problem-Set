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
    ll a, b; cin >> a >> b;
    ll sum = a + b;
    if(sum % 3) {
        cout << "NO" << endl;
    } else {
        if(a == b) {
            cout << "YES" << endl;
            return;
        }
        ll dif = abs(a - b);
        if(a > b) {
            a -= 2 * dif;
            b -= dif;
        } else {
            a -= dif;
            b -= 2 * dif;
        }
        if(a == b && a >= 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}

int main() {
    fastio;
    int t;
    cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

