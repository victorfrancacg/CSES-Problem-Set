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
    ll n, x; cin >> n >> x;
    ll out = 0;
    vll nums(n);
    rep0(i, n) {
        ll k; cin >> k;
        nums[i] = k;
    }
    
    //tem que ser um map, e não um unordered_map, uma vez que o unordered_map é implementado como hash table com solução chaining. Ou seja, as operações podem degenerar para O(n ** 2). Enquanto na rb tree (map<ll, ll>) será mantido sempre log(n)
    map<ll, ll> freq;
    freq[0] = 1;
    ll prefix = 0;
    for(ll num : nums) {
        prefix += num;
        if(freq.count(prefix - x)) {
            out += freq[prefix - x];
        }
        freq[prefix] ++;
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

