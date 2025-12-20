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

const int INF = 2 * 1e9;
const int MAX = 1e5;
vi nums(MAX, INF);
vi seg(4 * MAX);

int build(int p, int l, int r) {
    if(l == r) return seg[p] = nums[l];
    int m = (l + r) / 2;
    return seg[p] = min(build(2 * p, l, m), build(2 * p + 1, m + 1, r));
}

int query(int a, int b, int p, int l, int r) {
    if(l > b || r < a) return INF;
    if(l >= a && r <= b) return seg[p];
    int m = (l + r) / 2;
    return min(query(a, b, 2 * p, l, m), query(a, b, 2 * p + 1, m + 1, r));
}

int update(int i, int x, int p, int l, int r) {
    if(i < l || i > r) return seg[p];
    if(l == r) return seg[p] = x;
    int m = (l + r) / 2;
    return seg[p] = min(update(i, x, 2 * p, l, m), update(i, x, 2 * p + 1, m + 1, r));
}   

void solve() {
	int n, q; cin >> n >> q;
    nums.resize(n);
    seg.resize(4 * n);
    rep0(i, n) {
        cin >> nums[i];
    }
    build(1, 0, n - 1);
    rep0(i, q) {
        int type, a, b; cin >> type >> a >> b;
        a--;
        if(type == 2) {
            b--;
            cout << query(a, b, 1, 0, n - 1) << endl;
        } else {
            update(a, b, 1, 0, n - 1);
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

