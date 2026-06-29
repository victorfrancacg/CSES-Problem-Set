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

struct segtree {
    int n;
    vi tree;

    segtree(const vi& a) : n(a.size()), tree(4 * n) {
        build(1, 0, n - 1, a);
    }

    void build(int node, int l, int r, const vi& a) {
        if(l == r) {tree[node] = a[l]; return;}

        int mid = (l + r) / 2;

        build(2 * node, l, mid, a);

        build(2 * node + 1, mid + 1, r, a);

        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if(ql > r || qr < l) return 0;

        if(l >= ql && r <= qr) return tree[node];

        int mid = (l + r) / 2;

        return query(2 * node, l, mid, ql, qr) ^ query(2 * node + 1, mid + 1, r, ql, qr);
    }

    int query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
};

void solve() {
	int n, q; cin >> n >> q;
    vi nums(n);
    rep0(i, n) cin >> nums[i];
    segtree st(nums);

    rep0(i, q) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << st.query(l, r) << endl;
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

