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

void solve() {
    int n; cin >> n;
    vi nums(n);
    set<int> difs;
    rep0(i, n) {
        int x; cin >> x;
        nums[i] = x;
    }
    int out = 1;
    int atual = 1;
    
    int l = 0;
    int r = 1;
    difs.insert(nums[0]);
    while(l < n && r < n) {
        if(difs.count(nums[r]) > 0) {
            difs.erase(nums[l]);
            l++;
            atual--;
        } else {
            difs.insert(nums[r]);
            atual++;
            r++;
            out = max(atual, out);
        }
    }

    cout << out << endl;
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

