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

ll inicio = -1;
ll fim = -1;

string dfs(vector<bool> &visited, vector<vll> &adj, vll &parent, ll u) {
    visited[u] = true;
    for(auto v : adj[u]) {
        if(visited[v] && parent[u] != v) {
            inicio = u + 1;
            fim = v + 1;
            return "find";
        } else if (!visited[v]) {
            parent[v] = u;
            string out = dfs(visited, adj, parent, v);
            if(out == "find") return "find";
        }
    }
    return "no";
}

void solve() {
    ll n, m; cin >> n >> m;
    vector<vll> adj(n);
    rep0(i, m) {
        ll a, b; cin >> a >> b;
        adj[a-1].pb(b-1);
        adj[b-1].pb(a-1);
    }
    //achar qualquer ciclo no grafo
    vll parent(n);
    vector<bool> visited(n, false);
    string out = "";
    ll outt = 2;
    rep0(i, n) {
        //burro, só vamos rodar em componentes nao visitados
        if(!visited[i]) {
            if("find" == dfs(visited, adj, parent, i)) {
                out += to_string(fim) + " ";
                ll num = inicio - 1;
                while(num != fim - 1) {
                    outt++;
                    out += to_string(num + 1) + " ";
                    num = parent[num];
                }
                out += to_string(fim);
                break;
            }
        }
    }
    if(out == "") {
        cout << "IMPOSSIBLE" << endl;
    } else {
        cout << outt << endl;
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

