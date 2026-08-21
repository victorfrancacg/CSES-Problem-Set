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

void solve() {
    string s(9, '?'); 

    rep0(i, 3) {
        rep0(j, 3) cin >> s[i * 3 + j];
    }

    unordered_map<string, int> dist;
    dist.reserve(400000);
    dist.max_load_factor(0.7);

    vector<pii> swaps = {{0,1}, {0,3}, {1, 4}, {1, 2}, {2, 5}, {3, 4}, {3, 6}, {4, 5}, {4, 7}, {5, 8}, {6, 7}, {7, 8}}; 

    auto bfs = [&]() {
        queue<string> f; f.push(s);
        dist[s] = 0;
        if(s == "123456789") return;

        while(!f.empty())  {
            auto v = f.front(); f.pop();
            int d = dist[v];

            string aux;
            for(auto& troca : swaps) {
                aux = v;
                swap(aux[troca.fi], aux[troca.se]);

                auto it = dist.find(aux);

                if(it == dist.end()) {
                    dist[aux] = d + 1;
                    f.push(aux);
                    if(aux == "123456789") return;
                }
            }
        }
    };

    bfs();

    s = "123456789";

    cout << dist[s] << '\n';
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

