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


const ll MOD = 1e9 + 7;

ll fast_pow(ll base, ll exp) {
    ll out = 1;
    while(exp > 0) {
        if(exp % 2) {
            out = (out * base) % MOD;
        } 
        base = (base * base) % MOD;
        exp /= 2;
    }
    return out;
}

//exponenciação binária
void solve() {
    ll n; cin >> n;
    cout << fast_pow(2LL, n) << endl; 
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

