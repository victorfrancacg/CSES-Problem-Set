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

const int TAM = 200005;
int N, K;
vector<vi> adj(TAM);
vi depth(TAM);
//por subárvore, tenho um map de contagem de nós por profundidade
vector<map<int, ll>> cnt;
ll out = 0;

void dfs(int u, int parent) {
    depth[u] = (parent == -1 ? 0 : depth[parent] + 1);

    for(int v : adj[u]) {
        if(v == parent) continue;

        dfs(v, u);

        if(cnt[u].size() < cnt[v].size()) swap(cnt[u], cnt[v]);

        //pegando elementos de subarvores diferentes (o bent path)
        for(auto& [prof, qtd] : cnt[v]) {
            auto it = cnt[u].find(K + (2 * depth[u]) - prof);
            if(it != cnt[u].end()) out += qtd * it->second;
        }   

        //ordem: query --> merge. evita misturar vértices da mesma subárvore, o que quebraria a validade da heurística
        for(auto& [prof, qtd] : cnt[v]) cnt[u][prof] += qtd;
    }

    auto it = cnt[u].find(depth[u] + K);
    if(it != cnt[u].end()) out += it->second;

    cnt[u][depth[u]] += 1;
}

void solve() {
	cin >> N >> K;
    rep0(i, N - 1) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }

    cnt.assign(N, {});
    dfs(0, -1);
    cout << out << endl;
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

