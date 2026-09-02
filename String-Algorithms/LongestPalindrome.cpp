#include <bits/stdc++.h>
using namespace std;

#define ll long long
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

#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

mt19937 rng((int)
        chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r) {
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

template<int MOD> struct str_hash {
    static int P;
    vector<ll> h, p;

    str_hash(string s) : h(s.size()), p(s.size()) {
        p[0] = 1, h[0] = s[0];
        for(int i = 1; i < s.size(); i++) {
            p[i] = p[i-1] * P % MOD, h[i] = (h[i-1]*P + s[i]) % MOD;
        }

    }

    ll operator()(int l, int r) {
        ll hash = h[r] - (l ? h[l - 1]*p[r-l+1]%MOD : 0);
        return hash < 0 ? hash + MOD : hash;
    }   
};

template<int MOD> int str_hash<MOD>::P = uniform(256, MOD - 1);

void solve() {
    int lo = -1, hi = -1, best;

	string s; cin >> s;
    int n = (int)s.size();
    string t = s; reverse(all(t));

    int bodd = 0, beven = 0;

    str_hash<1000000007> h1(s);
    str_hash<1000000007> h2(t);

    int l = 1, r = n / 2;

    while(l <= r) {
        int mid = (l + r) >> 1;
        int k = 2 * mid;

        bool ok = false;
        for(int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if(h1(i, j) == h2(n - 1 - j, n - 1 - i)) {
                ok = true;
                if(k > best) {
                    lo = i, hi = j, best = k;
                }
                break;
            }       
        }       

        if(ok) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    l = 0, r = (n + 1) / 2;

    while(l <= r) {
        int mid = (l + r) >> 1;
        int k = 2 * mid + 1;

        bool ok = false;
        for(int i = 0; i < n - k + 1; i++) {
            int j = i + k - 1;
            if(h1(i, j) == h2(n - 1 - j, n - 1 - i)) {
                ok = true;
                if(k > best) {
                    lo = i, hi = j, best = k;
                }
                break;
            }       
        }       

        if(ok) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    for(int idx = lo; idx <= hi; idx++) cout << s[idx];
    cout << '\n';
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

