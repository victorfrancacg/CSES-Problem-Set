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
	map<int, int> rnk; set<int> a;

	vector<int> nums(n);

	for(int i = 0; i < n; i++) {cin >> nums[i]; a.insert(nums[i]);}
	
	int m = a.size();

	int i = 0;
	for(auto& v : a) {
		rnk[v] = i;
		i++;
	}

	for(int i = 0; i < n; i++) nums[i] = rnk[nums[i]];

	vector<int> freq(m, 0);
	vector<int> out;

	int x = 0;

	for(int i = 0; i < k; i++) {
		if(freq[nums[i]] == 0) {
			x++;
		}
		freq[nums[i]]++;
	}	
	
	out.push_back(x);
	int l = 0, r = k;

	while(r < n) {
		freq[nums[l]]--;
		if(freq[nums[l]] == 0) x--;

		freq[nums[r]]++;
		if(freq[nums[r]] == 1) x++;

		out.push_back(x);
		l++; r++;
	}


	for(auto& num : out) cout << num << " ";
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

