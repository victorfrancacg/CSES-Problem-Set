#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(x) x.begin(), x.end()
 
struct dsu {
    int n;
    vector<int> parent, sz;
    int comp;
 
    explicit dsu(int n) : n(n), parent(n + 1), sz(n + 1, 1) {
        iota(all(parent), 0);
        comp = n + 1;
    }
 
    int find(int x) {
        int root = parent[x];
 
        while(root != parent[root]) {
            root = parent[root];
        }
 
        while(parent[x] != root) {
            int aux = parent[x];
            parent[x] = root;
            x = aux;
        }
 
        return root;
    }
 
    bool unite(int x, int y) {
        int a = find(x), b = find(y);
 
        if(a == b) return false;
 
        comp--;
        if(sz[b] > sz[a]) swap(a, b);
        
        sz[a] += sz[b];
        parent[b] = a;
        return true;
    }
};
 
void solve() {
    int n; cin >> n;
    dsu tree(n);
 
    int m; cin >> m;
 
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        pq.push({c, a, b});
    }
 
    ll out = 0LL;
    while(!pq.empty()) {
        auto [c, a, b] = pq.top(); pq.pop();
 
        if(tree.unite(a, b)) {
            out += c;
        }
    }
 
    if(tree.comp == 2) {
        cout << out << '\n';
    } else {
        cout << "IMPOSSIBLE" << '\n';
    }
}
 
int main() {
    int t = 1; 
    //cin >> t;
 
    while(t--) solve();
 
    return 0;
}
