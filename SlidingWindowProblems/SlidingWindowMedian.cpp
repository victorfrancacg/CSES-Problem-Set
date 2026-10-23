#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

/*
	"It is tempting, if the only tool you have is a hammer, to treat everything as if it were a nail."
*/

void solve() {
	int n, k; cin >> n >> k;
	vector<int> nums(n), out;

	for(int i = 0; i < n; i++) cin >> nums[i];

	vector<int> aux;
	for(int i = 0; i < k; i++) aux.push_back(nums[i]); sort(all(aux));

	multiset<int> low, high;

	for(int i = 0; i < k; i++) {
		if(i < ((k + 1) / 2)) {
			low.insert(aux[i]);
		} else {
			high.insert(aux[i]);
		}
	}

	int l = 0, r = k - 1;

	while(r < n) {
		out.push_back((*low.rbegin()));

		int bye = nums[l];
		auto it = low.find(bye);
		bool removelow = false;
		if(it != low.end()) {
			low.erase(it);
			removelow = true;
		} else {
			high.erase(high.find(bye));
		}

		if(r + 1 < n) {
			int nv = nums[r + 1];
			
			if(removelow) {
				if(!high.size()) {
					low.insert(nv);
				} else {
					int fhigh = (*high.begin());
					if(nv > fhigh) {
						low.insert(fhigh);
						high.erase(high.begin());
						high.insert(nv);
					} else {
						low.insert(nv);
					}
				}
			} else {
				int llow = (*prev(low.end()));
				if(nv < llow) {
					high.insert(llow);
					low.erase(prev(low.end()));
					low.insert(nv);
				} else {
					high.insert(nv);
				}		
			}
		}	

		r++;
		l++;
	}

	for(auto& x : out) cout << x << " ";
	cout << '\n';
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

