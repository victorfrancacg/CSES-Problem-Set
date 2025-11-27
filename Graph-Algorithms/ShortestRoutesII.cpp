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

const ll INF = LLONG_MAX;

void solve() {
	ll n, m, q; cin >> n >> m >> q;
    vector<vll> dist(n + 1, vll(n + 1, INF));
    rep(i, 1, n + 1) {
        dist[i][i] = 0;
    }
    rep0(i, m) {
        ll a, b, c; cin >> a >> b >> c;
        if(c > dist[a][b] && c > dist[b][a]) {
            continue;
        }   
        dist[a][b] = c;
        dist[b][a] = c;
    }
    //dp
    //o k é o intermediario
    //O(1,25 * 1e8);
    rep(k, 1, n + 1) {
        rep(i, 1, n + 1) {
            rep(j, 1, n + 1) {
                if(dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    rep0(i, q) {
        ll a, b; cin >> a >> b;
        if(dist[a][b] == INF) {
            cout << -1 << endl;
            continue;
        }       
        cout << dist[a][b] << endl;
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

