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
    multiset<int> towers;
    vi nums(n);
    rep0(i, n) {
        cin >> nums[i];
    }
    
    towers.insert(nums[0]);
    int maior = nums[0];
    rep(i, 1, n) {  
        if(nums[i] >= maior) {
            //0(log n)
            towers.insert(nums[i]);
            maior = nums[i];
        } else {
            //O(log n)
            auto it = towers.upper_bound(nums[i]);
            towers.erase(it);
            towers.insert(nums[i]);
            //O(1)
            auto it2 = prev(towers.end());
            maior = *it2;
        }
    }   
    cout << towers.size() << endl;
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

