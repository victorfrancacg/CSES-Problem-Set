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
	ll out = LLONG_MIN;
    
    int n; cin >> n; vi nums(n);
    rep0(i, n) cin >> nums[i];

    vi lo(n, -1), hi(n, -1);

    stack<int> forward, backward;

    for(int i = 0; i < n; i++) {
        while(!forward.empty() && nums[forward.top()] >= nums[i]) {
            forward.pop();
        }

        if(!forward.empty()) lo[i] = forward.top();

        forward.push(i);
    }

    for(int i = n - 1; i >= 0; i--) {
        while(!backward.empty() && nums[backward.top()] >= nums[i]) {
            backward.pop();
        }

        if(!backward.empty()) hi[i] = backward.top();

        backward.push(i);
    }

    rep0(i, n) {
        int l, r;
    
        if(lo[i] == -1) l = i;
        else l = i - lo[i] - 1;

        if(hi[i] == -1) r = n -1 - i;
        else r = hi[i] - 1 - i;

        int base = l + r + 1;
/**
        if(nums[i] == 2) {
            cout << "base " << base << " altura " << nums[i] << endl;
            cout << "left " << l << " right " << r << endl;
            cout << "menor esquerda no indice " << lo[i] << endl;
        }
*/
        out = max(out, (ll)base * nums[i]);
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

