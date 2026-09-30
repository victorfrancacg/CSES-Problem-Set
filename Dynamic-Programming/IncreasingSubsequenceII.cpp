#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair

const ll MOD = 1e9 + 7;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

const int MAX = 200000;

namespace seg {
    ll seg[4 * MAX];

    int n, *v;

    ll build(int p = 1, int l = 0, int r = n - 1) {
        if(l == r) return seg[p] = v[l];
        int m = (l + r) >> 1;
        return seg[p] = (build(2 * p, l, m) + build(2 * p + 1, m + 1, r)) % MOD;
    }

    void build(int n2, int* v2) {
        n = n2, v = v2;
        build();
    }

    ll query(int a, int b, int p = 1, int l = 0, int r = n - 1) {
        if(a <= l && r <= b) return seg[p];

        if(b < l || r < a) return 0LL;

        int m = (l + r) >> 1;

        return (query(a, b, 2 * p, l, m) + query(a, b, 2 * p + 1, m + 1, r)) % MOD;
    }

    ll update(int idx, ll x, int p = 1, int l = 0, int r = n - 1) {
        if(l == r) {
            return seg[p] = (seg[p] + x) % MOD;
        }

        int m = (l + r) >> 1;

        if(idx <= m) {
            update(idx, x, 2 * p, l, m);
        } else {
            update(idx, x, 2 * p + 1, m + 1, r);
        }

        return seg[p] = (seg[2 *p] + seg[2 * p + 1]) % MOD;
    }
};

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    set<int> nums;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        nums.insert(a[i]);
    }
    map<int, int> rank;

    int r = 0;
    for(auto& x : nums) {
        rank[x] = r;
        r++;
    }

    ll out = n;
    vector<int> b(nums.size() + 1, 0);

    seg::build(nums.size() + 1, b.data());

    for(int i = 0; i < n; i++) {
        ll v = a[i];

        ll rnk = rank[v];
        ll subseqs = seg::query(0, rnk - 1);
        out = (out + subseqs) % MOD;
        seg::update(rnk, subseqs + 1);
    }

    cout << out << '\n';
}

int main() {
    fast_io();
    int t = 1;
    //cin >> t;
    while(t --) {
        solve();
    }
    return 0;
}

