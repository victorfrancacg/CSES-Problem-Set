#include <bits/stdc++.h>
 
using namespace std;
 
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)
#define ll long long
#define all(x) x.begin(), x.end()
 
/*
essa quase me custou a vida
 
Por que uma BFS ingenua mas com a mesma "Intencao" nao funciona?
 
Para achar um ciclo valido, eu tenho que achar alguem que ja foi visitado e, ao mesmo tempo, é ancestral (no path) do meu vertice atual
Nao tem como garantir isso com a solve ingenua de BFS. Pra capturar o conceito de "ancestral", preciso de PROFUNDIDADE
*/
 
void solve() {
    int n, m; cin >> n >> m;
 
    vector<int> color(n, 0);
    vector<vector<int>> adj(n);
 
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b; a--; b--;
        adj[a].push_back(b);
    }
 
    vector<int> out;
    vector<int> parent(n, -1);
 
    bool ok = false;
    auto dfs = [&](auto&& self, int v, bool& ok) -> void {
        if(ok) return;
        for(auto& viz : adj[v]) {
            parent[viz] = v;
            if(color[viz] == 1) {
                int aux = viz;
                out.push_back(viz);
                while(parent[aux] != viz) {
                    out.push_back(parent[aux]);
                    aux = parent[aux];
                }
                out.push_back(viz);
                ok = true;
                break;
            } else if(color[viz] == 0) {
                color[viz] = 1;
                self(self, viz, ok);
                if(ok) return;
            }
        }   
        color[v] = 2;
    };
 
    for(int i = 0; i < n; i++) {
        if(color[i] == 0 && !ok) {
            color[i] = 1;
            dfs(dfs, i, ok);
        }
    }
 
    reverse(all(out));
    if(out.size() == 0) {
        cout << "IMPOSSIBLE" << '\n';
    } else {
        cout << out.size() << '\n';
        for(auto& x : out) cout << x + 1 << " ";
        cout << '\n';
    }
 
} 
 
int main() {
    fastio;
    int t = 1;
    //cin >> t;
    while(t --) solve();
    return 0;
}
