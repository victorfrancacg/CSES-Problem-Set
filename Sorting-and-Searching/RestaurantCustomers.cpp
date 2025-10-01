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
    int n; cin >> n;
    ll out = 1;
    vi arrival(n);
    vi leaving(n);
    rep0(i, n) {
        int l, r; cin >> l >> r;
        arrival[i] = l;
        leaving[i] = r;
    }
    sort(all(arrival));
    sort(all(leaving));
    int l = 0;
    int lim = arrival.size();
    int r = 0;
    ll qtd = 1;
    while(l < lim - 1) {
        if(arrival[l + 1] < leaving[r]) {
            qtd = qtd + 1;
            l++;
        } else {
            qtd = qtd - 1;
            r++;
        }
        out = max(out, qtd);
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

