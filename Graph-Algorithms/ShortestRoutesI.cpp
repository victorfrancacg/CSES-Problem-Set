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
	ll n, m; cin >> n >> m;
    vll dist(n + 1, LLONG_MAX);
    dist[1] = 0;
    //direcionado && arestas com peso
    vector<vector<pll>> a(n + 1);
    rep0(i, m) {
        ll aa, b, c; cin >> aa >> b >> c;
        a[aa].pb(mp(b, c)); 
    }
    //quero descobrir a menor rota possível de 1 para todos os outros vértices;
    
    priority_queue<pll, vpll, greater<pll>> pq;
    pq.push(mp(0, 1));
    //ordenar pela menor dist dentro da min-heap

    while(!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if(d > dist[u]) continue;

        for(auto [v, w] : a[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push(mp(dist[v], v));
            } 
        }   
    }

    rep(i, 1, n + 1) {
        cout << dist[i] << " ";
    }
    cout << endl;
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

