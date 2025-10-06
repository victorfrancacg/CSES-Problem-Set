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
    ll n, k; cin >> n >> k;
    vpll nums(n);
    rep0(i, n) {
        ll x; cin >> x;
        nums[i] = mp(x, i + 1);
    }
    sort(all(nums));
    //O(n * n * log(n)), eu quero BARGANHAR
    rep0(i, n) {
        rep(j, i + 1, n) {
            ll soma = nums[i].fi + nums[j].fi;
            if(soma >= k) {
                continue;
            } else {
                ll dif = k - soma;
                auto it = lower_bound(all(nums), mp(dif, 0LL));
                pair<ll, ll> alvo = *it;
                if(alvo.fi != dif) {
                    continue;
                } else {
                    if(alvo.se != nums[i].se && alvo.se != nums[j].se) {
                        cout << nums[i].se << " " << nums[j].se << " " << alvo.se << endl;
                        return;
                    } else {
                        continue;
                    }
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;

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

