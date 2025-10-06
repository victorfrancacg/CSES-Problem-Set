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
    vll a(n);
    vector<pair<ll, pair<ll, ll>>> duplas;
    rep0(i, n) {
        ll k; cin >> k;
        a[i] = k;
    }

    //10e6, guarda todas as duplas;
    rep0(i, n) {
        rep(j, i + 1, n) {
            duplas.pb(mp(a[i] + a[j], mp(i + 1, j + 1)));
        }
    }

    //as duplas garantidamente já sao de indices distintos

    sort(all(duplas));
    ll d = duplas.size();
    //10e6 * log(10e6)
    rep0(i, d) {
        ll dif = x - duplas[i].fi;
        if(dif <= 1) {
            continue;
        } else {
            auto it = lower_bound(all(duplas), mp(dif, mp(0LL, 0LL)));
            pair<ll, pair<ll, ll>> alvo = *it;
            if(alvo.fi == dif && duplas[i].se.fi != alvo.se.fi && duplas[i].se.fi != alvo.se.se && duplas[i].se.se != alvo.se.fi && duplas[i].se.se != alvo.se.se) {
                cout << duplas[i].se.fi << " " << duplas[i].se.se << " " << alvo.se.fi << " " << alvo.se.se << endl;
                return;
            } else {
                continue;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
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

