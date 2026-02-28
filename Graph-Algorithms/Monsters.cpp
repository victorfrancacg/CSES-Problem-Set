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

const int INF = 1e9;

void solve() {
	int n, m; cin >> n >> m;
    pii st;
    vector<vector<pii>> parent(n, vector<pii>(m));
    vector<vector<char>> mat(n, vector<char>(m));
    vector<vi> dist_m(n, vi(m, INF));
    vector<vi> dist_p(n, vi(m, INF));
    vpii monstros;
    rep0(i, n) {
        rep0(j, m) {
            char c; cin >> c;
            mat[i][j] = c;
            if(c == 'A') {
                st.fi = i; st.se = j;
            } else if (c == 'M') {
                monstros.pb(mp(i, j));
            }
        }   
    }

    queue<pii> fila;
    for(auto x : monstros) {
        dist_m[x.fi][x.se] = 0;
        fila.push(x);
    }

    while(!fila.empty()) {
        auto at = fila.front(); fila.pop();
        int v = dist_m[at.fi][at.se];
        int x = at.fi; int y = at.se;
        if(x + 1 < n && mat[x+1][y] != '#' && dist_m[x+1][y] == INF) {
            dist_m[x+1][y] = v + 1;
            fila.push(mp(x+1,y));
        }
        if(x - 1 >= 0 && mat[x-1][y] != '#' && dist_m[x-1][y] == INF) {
            dist_m[x-1][y] = v + 1;
            fila.push(mp(x-1,y));
        }
        if(y - 1 >= 0 && mat[x][y-1] != '#' && dist_m[x][y-1] == INF) {
            dist_m[x][y-1] = v + 1;
            fila.push(mp(x, y-1));
        }
        if(y + 1 < m && mat[x][y+1] != '#' && dist_m[x][y+1] == INF) {
            dist_m[x][y+1] = v + 1;
            fila.push(mp(x, y+1));
        }
    }

    queue<pii> fila2;
    dist_p[st.fi][st.se] = 0;
    fila2.push(st);
    while(!fila2.empty()) {
        auto at = fila2.front(); fila2.pop();
        int v = dist_p[at.fi][at.se];
        int x = at.fi; int y = at.se;
        if(x + 1 < n && mat[x+1][y] != '#' && dist_p[x+1][y] == INF && dist_m[x+1][y] > v + 1) {
            dist_p[x+1][y] = v + 1;
            fila2.push(mp(x+1,y));
            parent[x+1][y] = at;
        }
        if(x - 1 >= 0 && mat[x-1][y] != '#' && dist_p[x-1][y] == INF && dist_m[x-1][y] > v + 1) {
            dist_p[x-1][y] = v + 1;
            fila2.push(mp(x-1,y));
            parent[x-1][y] = at;
        }
        if(y - 1 >= 0 && mat[x][y-1] != '#' && dist_p[x][y-1] == INF && dist_m[x][y-1] > v + 1) {
            dist_p[x][y-1] = v + 1;
            fila2.push(mp(x, y-1));
            parent[x][y-1] = at;
        }
        if(y + 1 < m && mat[x][y+1] != '#' && dist_p[x][y+1] == INF && dist_m[x][y+1] > v + 1) {
            dist_p[x][y+1] = v + 1;
            fila2.push(mp(x, y+1));
            parent[x][y+1] = at;
        }
    }

    int x1 = 0; int x2 = n - 1;
    int y1 = 0; int y2 = m - 1;
    bool ok = false;
    pii ref;
    rep0(i, m) {
        if(dist_p[x1][i] < dist_m[x1][i]) {
            ok = true;
            ref.fi = x1; ref.se = i;
            break;
        }
        if(dist_p[x2][i] < dist_m[x2][i]) {
            ok = true;
            ref.fi = x2; ref.se = i;
            break;
        }
    }
    if(!ok) {
        rep0(i, n) {
            if(dist_p[i][y1] < dist_m[i][y1]) {
                ok = true;
                ref.fi = i; ref.se = y1;
                break;
            }
            if(dist_p[i][y2] < dist_m[i][y2]) {
                ok = true;
                ref.fi = i; ref.se = y2;
                break;
            }
        }
    }
    if(!ok) {
        cout << "NO" << endl;
    } else {
        string out = "";
        while(ref !=  st) {
            pii father = parent[ref.fi][ref.se];

            int dx = ref.fi - father.fi; int dy = ref.se - father.se;
            if(dx == 1) out +=  'D';
            else if(dx == -1) out += 'U';
            else if(dy == 1) out += 'R';
            else if(dy == -1) out += 'L';

            ref = father;
        }
        cout << "YES" << endl;
        cout << out.size() << endl;
        reverse(all(out));
        cout << out << endl;
    }
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

