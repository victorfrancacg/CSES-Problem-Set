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

const int B = 32;

struct trie {
    //cada nó guarda dois pseudoponteiros: quem é o filho por 1 e quem é o filho por 0
    vector<array<int, 2>> ch;
    //root
    trie() {ch.pb({-1, -1});}

    void insert(int x) {
        int cur = 0;
        for(int i = B - 1; i >= 0; i--) {
            int b = (x >> i) & 1;
            //adição preguiçosa
            if(ch[cur][b] == -1) {
                ch[cur][b] = ch.size();
                ch.pb({-1, -1});
            }
            cur = ch[cur][b];
        }
    }   

    int query(int x) {
        int cur = 0, res = 0;

        for(int i = B - 1; i >= 0; i--) {
            int b = (x >> i) & 1;
            //argumento guloso um só 2^x é melhor que todos os 2^x-1 (...) 2^0
            int want = b ^ 1;
            if(ch[cur][want] != -1) {
                res |= (1 << i);
                cur = ch[cur][want];
            } else {
                cur = ch[cur][b];
            }
        }

        return res;
    }
};

void solve() {
    int n; cin >> n;
    vi nums(n); rep0(i, n) cin >> nums[i];

    trie t; t.insert(0);

    int pref = 0, out = 0;
    rep0(i, n) {
        pref ^= nums[i];
        out = max(out, t.query(pref));
        t.insert(pref);
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


