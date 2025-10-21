#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
 
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define rep0(i, a) rep(i, 0, a)
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define pb push_back
#define pop pop_back
 
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}
 
struct Point {
    ll x, y;
    bool operator<(const Point& other) const {
        return (x < other.x) || (x == other.x && y < other.y);
    }
};
 
ll cross(const Point& O, const Point& A, const Point& B) {
    return (A.x - O.x) * (B.y - O.y) - (B.x - O.x) * (A.y - O.y);
}
 
vector<Point> convex_hull(vector<Point>& in) {
    int n = in.size(), k = 0;
    if(n <= 1) {
        return in;
    }
 
    sort(all(in));
    vector<Point> hull(2 * n);
 
    for(int i = 0; i < n; ++i) {
        while(k >= 2 && cross(hull[k - 2], hull[k - 1], in[i]) < 0) k--;
        hull[k++] = in[i];
    }
 
    for(int i = n - 2, t = k; i >= 0; --i) {
        while(k >= t && cross(hull[k - 2], hull[k - 1], in[i]) < 0) k--;
        hull[k++] = in[i];
    }
 
    hull.resize(k - 1);
    return hull;
}
 
void solve() {
    int n; cin >> n;
    vector<Point> in(n);
 
    rep0(i, n) {
        cin >> in[i].x >> in[i].y;
    }
 
    vector<Point> out = convex_hull(in);
 
    set<Point> outt;
 
    for(auto p : out) {
        outt.insert(p);
    }
 
    cout << outt.size() << endl;
    for(auto p : outt) {
        cout << p.x << " " << p.y << endl;
    }
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

