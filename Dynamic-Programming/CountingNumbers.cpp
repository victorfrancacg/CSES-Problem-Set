#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

string N;
ll dp[20][11];
bool vis[20][11];

ll go(int faltam, int last, bool tight) {
    if(faltam == 0) return 1;
    if(!tight && vis[faltam][last]) return dp[faltam][last];

    int pos = (int)N.size() - faltam;
    int lim = tight ? N[pos] - '0' : 9;
    ll res = 0;
    for(int d = 0; d <= lim; d++) {
        if(last != 10 && d == last) continue;
        int nlast = (last == 10 && d == 0) ? 10 : d;

        res += go(faltam - 1, nlast, tight && d == lim);
    }

    if(!tight) {vis[faltam][last] = true; dp[faltam][last] = res;}

    return res;
}

ll f(ll n) {
    N = to_string(n);
    return go(N.size(), 10, true);
}

void solve() {
    ll lo, hi; cin >> lo >> hi;

    //o que meu estado precisa guardar? 
    //1. qtd digitos
    //2. qual foi o último dígito inserido
    //dp[i][last]
    //não se pode gerar números maiores que hi, nem menores que lo
    //res = res[hi] - res[lo-1]
    //fixar comprimento com zeros à esquerda
    //flag tight == true na posicao pos <-> o prefixo construído é idêntico ao prefixo de N de mesmo tamanho
    //zeros à esquerda podem atrapalhar a contagem do problema:
    //
    //00005 (contém zeros adjacentes) porém o número real é 5 (válido).
    //disso decorre uma nova flag started (já saiu algum dígito não-zero?)
    //enquanto !started, não se compara com last
    //nlast = (last == 10 && d == 0)? 10 : d
    //dp[post][last] com last e [0, 10]
    
    cout << f(hi) - f(lo - 1) << '\n';
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

