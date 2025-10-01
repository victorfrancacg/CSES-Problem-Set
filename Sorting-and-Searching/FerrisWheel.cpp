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
    ll n, x; cin >> n >> x;
    ll out = 0;
    vll menores;
    vll maiores;
    rep0(i, n) {
        ll w; cin >> w;
        if(w <= x / 2) {
            menores.pb(w);
        } else {
            maiores.pb(w);
        }
    }

    sort(all(menores));
    sort(all(maiores));
    int l = 0;
    int lim = menores.size();
    int r = maiores.size() - 1;
    while(l < lim && r >= 0) {
        if(menores[l] + maiores[r] <= x) {
            l++;
        }
        out++;
        r--;
    }
    

    while(l < lim) {
        if(l == lim - 1) {
            out++;
            l++;
        } else {
            if(menores[l] + menores[l + 1] <= x) {
                out++;
                l += 2;
            } else {
                out += 2;
                l += 2;
            }
        }
    }

    if(r >= 0) {
        out += r + 1;
    }

    cout << out << endl;
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

