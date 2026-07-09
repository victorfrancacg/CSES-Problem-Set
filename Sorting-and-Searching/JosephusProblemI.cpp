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
    
    list<int> nums;
    rep0(i, n) {
        nums.pb(i + 1);
    }

//toma da linked list
    auto it = nums.begin();
    bool ok = false;
    while(nums.size() != 0) {
        if(!ok) {
            if(next(it) == nums.end()) it = nums.begin();
            else it = next(it);
            ok = true; 
        } else {
            cout << *it << " ";
            auto aux = next(it);
            nums.erase(it);
            if(aux == nums.end()) it = nums.begin();
            else it = aux;
            ok = false;
        }
    }

    cout << endl;
}


int main() {
    fastio;
    int t = 1;
//    cin >> t;
    while(t--) {
	    solve();
    }

    return 0;
}

