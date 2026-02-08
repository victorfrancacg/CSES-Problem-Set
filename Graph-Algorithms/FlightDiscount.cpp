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

//rodar Dijkstra de dois estados: Teremos duas informações na lista DIST:
//menor DIST for each vertex sem usar o cupom AND menor DIST for each vertex usando o cupom

void solve() {
	ll n, m; cin >> n >> m;
    vector<vpll> adj(n + 1);

    rep0(i, m) {
        ll a, b, c; cin >> a >> b >> c;
        adj[a].pb(mp(b, c));
    }

    vector<vll> dist(n + 1, vll(2, LLONG_MAX));
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<>> pq;

    pq.push({0, 1, 0});

    while(!pq.empty()) {
        auto [d, u, estado] = pq.top();
        pq.pop();

        if(d > dist[u][estado]) continue;
    
        //aqui roda o dijkstra normal
        for(auto[v, w] : adj[u]) {
            if(d + w < dist[v][estado]) {
                dist[v][estado] = d + w;
                pq.push({dist[v][estado], v, estado});
            }
            
            //se ainda nao usamos o cupom, vamos testar usar agora
            if(estado == 0) {
                ll desconto = w / 2;
                //pq dist[v][1]? pq estamos chegando em v utilizando o cupom agora, ou seja, antes de chegar em V 
                if(d + desconto < dist[v][1]) {
                    dist[v][1] = d + desconto;
                    pq.push({dist[v][1], v, 1});
                }
            }
        }
    }

    cout << dist[n][1] << endl;
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

