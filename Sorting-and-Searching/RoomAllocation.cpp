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
    set<pii> ent, sai;
    rep0(i, n) {
        int a, b; cin >> a >> b;

        ent.insert(mp(a, i + 1));
        sai.insert(mp(b, i + 1));
    }

    int rid = 1;
    map<int, int> alloc;
    for(auto& [e, id] : ent) {
        //preciso encontrar um cara que sai antes. Se tem, eles ficam no mesmo quarto
        auto it = sai.lower_bound(mp(e, 0));
        if(it == sai.begin()) {
            alloc[id] = rid;
            rid++;
            continue;
        } 

        it--;
        auto& [e2, id2] = *it;
        alloc[id] = alloc[id2];

        //preciso apagar para evitar gula demais quanto aos novos hóspedes
        sai.erase(it);
    }

    cout << rid - 1 << endl;
    for(auto& [hosp, room] : alloc) {
        cout << room << " ";
    }
    cout << endl;
}

int main() {
    fastio;
    int t = 1;
   // cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

