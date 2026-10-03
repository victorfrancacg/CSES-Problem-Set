#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

int SIZE; //denotes the length of a block (sqrt decomp)

vector<int> a, cnt, solve;
vector<array<int, 3>> nums;
int curL = 0, curR = -1, ans = 0;

void add(int idx) {
	if(++cnt[a[idx]] == 1) ans++;
}

void rem(int idx) {
	if(--cnt[a[idx]] == 0) ans--;
}

void query(int l, int r, int id) {
	while(curL < l) rem(curL++); 
	while(curL > l)	add(--curL);
	while(curR < r) add(++curR);
	while(curR > r) rem(curR--);
	
	solve[id] = ans;
	return;
}

int main() {
    fastio;

	int n, q; cin >> n >> q;
	a.resize(n);
	nums.resize(q);
	solve.resize(q);

	map<int, int> rnk;
	set<int> dif;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		dif.insert(a[i]);
	}

	for(auto& x : dif) {
		rnk[x] = rnk.size();
	}		

	for(auto& ele : a) {
		ele = rnk[ele];
	}

	cnt.resize((int)rnk.size());

	for(int i = 0; i < q; i++) {
		int a, b; cin >> a >> b; a--; b--;
		nums[i] = {a, b, i};
		solve[i] = 0;
	}

	SIZE = max(1, (int)sqrt(n));
	sort(all(nums), [&](const array<int, 3>& x, const array<int, 3>& y) {
		//the first criterion is to divide the array into SIZE groups
		if(x[0] / SIZE != y[0] / SIZE) return x[0] / SIZE < y[0] / SIZE;
		//how to escape TLE: odd-even trick --> the complexity proof only needs that, inside every block, r is monotone. 
		//ordering r in odd blocks decrease-order evict the rewind at every block switch
		if((x[0] / SIZE) & 1) return x[1] > y[1];
		return x[1] < y[1];
	});

	for(auto& [l, r, id] : nums) query(l, r, id);

	for(auto& v : solve) {
		cout << v << '\n';
	}

    return 0;
}

