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

struct DSU {
    vi sz, parent;
    int comp, largest;

    explicit DSU(int n) : sz(n, 1), parent(n) {
        iota(all(parent), 0);
        comp = n;
        largest = 1;
    }

    int find(int x) {
        int root = x;
        while(parent[root] != root) root = parent[root];

        while(parent[x] != root) {
            int next = parent[x];
            parent[x] = root;
            x = next;
        }

        return root;
    }

    bool unite(int x, int y) {
        int a = find(x), b = find(y);

        if(a == b) return false;

        if(sz[b] > sz[a]) swap(a, b);

        sz[a] += sz[b];

        largest = max(largest, sz[a]);
        comp--;

        parent[b] = a;

        return true;
    }
};

void solve() {
	int n, m; cin >> n >> m;
    DSU dsu(n);
    rep0(i, m) {
        int a, b; cin >> a >> b; a--; b--;
        dsu.unite(a, b);
        cout << dsu.comp << " " << dsu.largest << endl;
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

