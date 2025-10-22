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
    string s; cin >> s;
    int n = s.size();
    map<char, int> freq;
    rep0(i, n) {
        freq[s[i]]++;
    }
    bool imp = false;
    char tal;
    for(auto& [ch, v] : freq) {
        if(v % 2 && !imp) {
            imp = true;
            tal = ch;
        } else if(v % 2 && imp) {
            cout << "NO SOLUTION" << endl;
            return;
        }
    }
    string out(n, '?');
    int l = 0;
    int r = n - 1;
    while(l < r) {
        auto par = *freq.begin();
        if(par.se > 1) {
            out[l] = par.fi; out[r] = par.fi;
            l++; r--;
            freq[par.fi] -= 2;

            if(freq[par.fi] == 0) {
                freq.erase(freq.begin());
            }
        } else {
            freq.erase(freq.begin());
        }
    }
    if(imp) {
        out[l] = tal;
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

