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
    vll t;

    segtree(const vll& a) : n(a.size()), t(4 * n) {
        build(1, 0, n - 1, a);
    }

    void build(ll node, int l, int r, const vll& a) {
        if(l == r) {t[node] = a[l]; return;}

        int mid = (l + r) / 2;
        
        build(2 * node, l, mid, a);
        build(2 * node + 1, mid + 1, r, a);
    
        t[node] = t[2 * node] + t[2 * node + 1];
    }

    void update(int node, int l, int r, int i, int x) {
        if(l == r) {t[node] = x; return;}

        int mid = (l + r) / 2;

        if(i <= mid) update(2 * node, l, mid, i, x);
        else update(2 * node + 1, mid + 1, r, i, x);

        t[node] = t[2 * node] + t[2 * node + 1];
    }

    void update(int i, int x) {
        return update(1, 0, n - 1, i, x);
    };

    ll query(ll node, int l, int r, int ql, int qr) {
        if(qr < l || r < ql) return 0;

        if(l >= ql && r <= qr) return t[node];

        int mid = (l + r) / 2;

        return (query(2 * node, l, mid, ql, qr) + query(2 * node + 1, mid + 1, r, ql, qr));
    }

    ll query(int l, int r) {
        return query(1, 0, n - 1, l, r);
    }

};

void solve() {
	ll n, q; cin >> n >> q;
    vll nums(n); rep0(i, n) cin >> nums[i];

    segtree st(nums);

    rep0(i, q) {
        int a, b, c; cin >> a >> b >> c;

        if(a == 1) {
            b--;
            st.update(b, c);
        } else {
            b--; c--;
            cout << st.query(b, c) << endl;
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

