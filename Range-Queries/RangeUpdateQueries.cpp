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
    vll tree;
    vll lazy;

    segtree(const vll& a) : n(a.size()), tree(4 * n), lazy(4 * n) {
        build(1, 0, n - 1, a);
    }

    void build(ll node, int l, int r, const vll& a) {
        if(l == r) {tree[node] = a[l]; return;}

        int mid = (l + r) / 2;

        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
        
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }   

    void apply(ll node, int lo, int hi, ll u) {
        tree[node] += (ll)(hi - lo + 1) * u;

        lazy[node] += u;
    }

    void push_down(ll node, int lo, int hi) {
        if(lazy[node] == 0) return;
        
        int mid = (lo + hi) / 2;

        apply(2 * node, lo, mid, lazy[node]);
        apply(2 * node + 1, mid + 1, hi, lazy[node]);
        lazy[node] = 0;
    }

    void update(ll node, int l, int r, int ql, int qr, ll u) {
        if(ql > r || qr < l) return;

        if(ql <= l && r <= qr) {apply(node, l, r, u); return;}

        push_down(node, l, r);

        int mid = (l + r) / 2;

        update(2 * node, l, mid, ql, qr, u);
        update(2 * node + 1, mid + 1, r, ql, qr, u);

        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }   

    ll query(ll node, int l, int r, int ql, int qr) {
        if(qr < l || ql > r) return 0;
        if(ql <= l && r <= qr) return tree[node];
        push_down(node, l, r);
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr);
    }

    void update(int ql, int qr, ll u) {
        return update(1, 0, n -1, ql, qr, u);
    }

    ll query(int ql, int qr) {
        return query(1, 0, n-1, ql, qr);
    }
};

void solve() {
	int n, q; cin >> n >> q;

    vll nums(n);
    rep0(i, n) cin >> nums[i];

    segtree st(nums);

    rep0(i, q) {
        int type; cin >> type;

        if(type == 1) {
            int l, r, u; cin >> l >> r >> u;
            l--; r--;
            st.update(l, r, u);
        } else {
            int k; cin >> k; k--;
            cout << st.query(k, k) << endl;
        }
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

