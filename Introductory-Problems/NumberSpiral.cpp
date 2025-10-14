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
    ll i, j; cin >> i >> j;	
    if(i == j) {
        cout << i * i - (i - 1) << endl;
    } else {
        ll res;
        if(i > j) {
            if(i % 2) {
                res = (i - 1) * (i - 1) + j;
            } else {
                res = (i * i) - (j - 1);
            }
        } else {
            if(j % 2) {
                res = (j * j) - (i - 1); 
            } else {
                res = (j - 1) * (j - 1) + i;
            }
        }


        cout << res << endl;
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

