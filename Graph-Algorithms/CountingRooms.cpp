#include <bits/stdc++.h>
using namespace std;
 
// Type definitions
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
// Macros for loops
#define mp make_pair
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pop pop_back
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
void visita(int i, int j, vector<vector<bool>>& vis, vector<string>& mat) {
    vis[i][j] = true;
    if(i - 1 >= 0 && !vis[i - 1][j] && mat[i - 1][j] == '.') {
        visita(i - 1, j, vis, mat);
    } 
    if(i + 1 < mat.size() && !vis[i + 1][j] && mat[i + 1][j] == '.') {
        visita(i + 1, j, vis, mat);
    }
    if(j + 1 < mat[0].size() && !vis[i][j + 1] && mat[i][j + 1] == '.') {
        visita(i, j + 1, vis, mat);
    }
    if(j - 1 >= 0 && !vis[i][j - 1] && mat[i][j - 1] == '.') {
        visita(i, j - 1, vis, mat);
    }
}
 
void solve() {
    int out = 0;
    int n, m; cin >> n >> m;
    vector<string> mat(n);
    rep0(i, n) {
        string s; cin >> s;
        mat[i] = s;
    }
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    rep0(i, n) {
        rep0(j, m) {
            if(mat[i][j] == '.' && !vis[i][j]) {
                visita(i, j, vis, mat);
                out++;
            } 
        }
    }
    cout << out << endl;
 
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

