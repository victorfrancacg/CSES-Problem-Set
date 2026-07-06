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

vector<vi> adj;
vi c;
vector<set<int>> conjs;
vi sizes;

void dfs(int node, int parent) {
//    cout << node << endl;
    if(node != 0 && adj[node].size() == 1) {conjs[node].insert(c[node]); sizes[node] = 1; return;}

    for(int viz : adj[node]) {
        if(viz == parent) continue;

        dfs(viz, node);

        if(conjs[viz].size() > conjs[node].size()) swap(conjs[viz], conjs[node]);

        for(auto& ele : conjs[viz]) conjs[node].insert(ele);

        conjs[viz].clear();

    }

    conjs[node].insert(c[node]);
    sizes[node] = conjs[node].size();

    return;
}   

void solve() {
	int n; cin >> n;
    c.assign(n, 0);
    adj.assign(n, {});
    conjs.assign(n, {});
    sizes.assign(n, 0);
    rep0(i, n) cin >> c[i];

    rep0(i, n - 1) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].pb(b); adj[b].pb(a);
    }   

    dfs(0, -1);

    rep0(i, n) {
        cout << sizes[i] << " ";
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


