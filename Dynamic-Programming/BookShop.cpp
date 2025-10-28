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
    //tabela de n + 1 linhas e x + 1 colunas, x + 1 representa a melhor escolha de 0 até x;
    vector<vector<ll>> dp(n + 1, vector<ll>(x + 1)); vector<ll> pages(n); vector<ll> prices(n);
    rep0(i, n) {
        cin >> prices[i];
    }
    rep0(i, n) {
        cin >> pages[i];
    }
    vpll books(n);
    rep0(i, n) {
        books[i] = mp(prices[i], pages[i]);
    }
    sort(all(books));
    //monta-se uma matriz, cada linha representa a possibilidade de adicionar um novo livro com preço 'p'. Cada coluna, representa a melhor escolha com um budget 'x', considerando a inclusão ou não daquele novo livro. Quais valores a dp pode assumir?
    //1: 0, caso voce nao leve nenhum livro ou nao tenha dinheiro suficiente para isso.
    //2: dp[i - 1][soma] o valor da linha anterior - ou seja, não é ótimo levar esse novo livro com esse peso.
    //3: books[i - 1].se + dp[i - 1][soma - books[i - 1].fi]. Ou seja, é ótimo levar esse novo livro. Só que pode sobrar dinheiro e, então, temos que procurar na linha de cima qual é a melhor coisa a se levar com esse troco.
    rep(i, 1, n + 1) {
        rep0(soma, x + 1) {
            dp[i][soma] = dp[i - 1][soma];
            if(books[i - 1].fi <= soma) {
                dp[i][soma] = max(dp[i][soma], books[i - 1].se + dp[i - 1][soma - books[i - 1].fi]);
            }
        }
    }

    cout << dp[n][x] << endl;
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

