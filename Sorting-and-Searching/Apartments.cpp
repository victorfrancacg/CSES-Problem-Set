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
    int n, m, k; cin >> n >> m >> k;
    vi clients(n);
    vi apt(m);
    rep0(i, n) {
        int x; cin >> x;
        clients[i] = x;
    }
    rep0(i, m) {
        cin >> apt[i];
    }
    sort(all(apt));
    sort(all(clients));
    int out = 0;
    
    int i = 0;
    int l = 0;
    //max. operações: 4 * 10e5 ??
    while(l < n && i < m) {
        int client = clients[l];
        if(apt[i] >= client - k && apt[i] <= client + k) {
            out++;
            l++;
            i++;
        } else {
            if(client < apt[i]) {
                l++; 
            } else {
                i++;
            }
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

