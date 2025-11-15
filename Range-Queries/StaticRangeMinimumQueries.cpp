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
	ll n, q; cin >> n >> q;
    vll nums(n);
    rep0(i, n) {
        cin >> nums[i];
    }
    // 2 ** 20 um pouco acima de um milhao, suficiente
    vector<vll> st(n, vll(20));
    rep0(i, n) {
        //primeiro nivel da sparse table preenchido: 2e0;
        st[i][0] = nums[i];
    }
    //como preencher níveis maiores?
    for(ll k = 1; (1 << k) <= n; k++) {
        //computamos cada intervalo 2^k possivel, começando de i e nao ultrapassando o lim do array
        for(ll i = 0; i + (1 << k) <= n; i++) {
            st[i][k] = min(st[i][k - 1], st[i + (1 << (k-1))][k-1]);
        }
    }   

    vll lg(n + 1);
    lg[1] = 0;

    //pré computando os logaritmos para cada tamanho;
    rep(i, 2, n + 1) {
        lg[i] = lg[i / 2] + 1;
    }

    //query respondida em O(1)
    //respondendo queries
    rep0(i, q) {
        ll l, r; cin >> l >> r; l--; r--;
        //tamanho do meu int
        ll len = r - l + 1;
        //blocos que eu precisarei para responder. ex: len = 10, lg[10] = 3; vou usar dois intervalos de tam 8 sobrepostos para responder.
        ll k = lg[len];
        //sobrepor intervalos ( ou nao);
        cout << min(st[l][k], st[r - (1 << k) + 1][k]) << endl;
    }
    //conclusao: O(n * log (n) + q);
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

