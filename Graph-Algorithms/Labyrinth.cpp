#include <bits/stdc++.h>
using namespace std;
 
// Type definitions
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
// Macros for loops
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define fi first
#define se second
#define mp make_pair
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void solve() {
    int n, m; cin >> n >> m;
    vector<vector<pii>> parent(n, vector<pii>(m));
    vector<vector<bool>> vis(n, vector<bool>(m, true));
    vector<vector<char>> a(n, vector<char>(m));
    int ini, inii;
    int fim, fimm;
    rep0(i, n) {
        rep0(j, m) {
            char c; cin >> c;
            a[i][j] = c;
            if(c == 'A' || c == 'B' || c == '.') {
                vis[i][j] = false;
            }
            if(c == 'A') {
                ini = i;
                inii = j;
            }
            if(c == 'B') {
                fim = i;
                fimm = j;
            }
        }
    }
    queue<pii> fila;
    int q = 0;
    fila.push(mp(ini, inii));
    vis[ini][inii] = true;
    while(!fila.empty()) {
        pii atual = fila.front();
        fila.pop();
        if(a[atual.fi][atual.se] == 'B') {
            break;
        } else {
            if(atual.fi + 1 < n && !vis[atual.fi + 1][atual.se]) {
                vis[atual.fi + 1][atual.se] = true;
                parent[atual.fi + 1][atual.se] = atual;
                fila.push(mp(atual.fi + 1, atual.se));
            }
            if(atual.fi - 1 >= 0 && !vis[atual.fi - 1][atual.se]) {
                vis[atual.fi - 1][atual.se] = true;
                parent[atual.fi - 1][atual.se] = atual;
                fila.push(mp(atual.fi - 1, atual.se));
            }
            if(atual.se + 1 < m && !vis[atual.fi][atual.se + 1]) {
                vis[atual.fi][atual.se + 1] = true;
                parent[atual.fi][atual.se + 1] = atual;
                fila.push(mp(atual.fi, atual.se + 1));
            }
            if(atual.se - 1 >= 0 && !vis[atual.fi][atual.se - 1]) {
                vis[atual.fi][atual.se - 1] = true;
                parent[atual.fi][atual.se - 1] = atual;
                fila.push(mp(atual.fi, atual.se - 1));
            }
        }
    }
    if(vis[fim][fimm]) {
        cout << "YES" << endl;
        pii atual = mp(fim, fimm);
        pii inicio = mp(ini, inii);
        string s;
        while(atual != inicio) {
            q++;
            int i = atual.fi;
            int j = atual.se;
            int ii = parent[i][j].fi;
            int jj = parent[i][j].se;
            if(ii == i + 1) {
                s += 'U';
            } else if(ii == i - 1) {
                s += 'D';
            } else if(jj == j - 1) {
                s += 'R';
            } else {
                s += 'L';
            }
            atual = parent[i][j];
        }
        reverse(all(s));
        cout << q << endl;
        cout << s << endl;
    } else {
        cout << "NO" << endl;
    }
 
}
 
int main() {
    fast_io();
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}

