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
    vll pages(n), prices(n); vpll books(n);
    rep0(i, n) {
        cin >> prices[i];
    }
    rep0(i, n) {
        cin >> pages[i];
    }
    rep0(i, n) {
        books[i] = mp(prices[i], pages[i]);
    }
    sort(all(books));

    //essa otimização pode acontecer já que o desempenho máximo só se baseia na LINHA anterior e, portanto, só precisa 'se lembrar' dos ultimos valores em cada coluna. Por isso max(dp[soma], dp[soma - price] + pages).
    //Por que percorre de trás pra frente? Garantir que não se use o novo livro duas vezes (sobrescrição)
    vector<ll> dp(x + 1, 0);
    
    rep0(i, n) {
        ll price = books[i].fi;
        ll pages = books[i].se;
    
        for(ll soma = x; soma >= price; soma--) {
            dp[soma] = max(dp[soma], dp[soma - price] + pages);
        }
    }

    cout << dp[x] << endl;
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

