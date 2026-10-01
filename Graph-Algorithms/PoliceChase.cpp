#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) (x).begin(), (x).end()
#define fastio ios_base::sync_with_stdio(false), cin.tie(nullptr)

const int INF = 1e9;

template<typename T> struct mcmf {
	struct edge {
		int to, rev, flow, cap;
		bool res;
		T cost;
		edge() : to(0), rev(0), flow(0), cap(0), cost(0), res(false) {}
		edge(int to_, int rev_, int flow_, int cap_, T cost_, bool res_)
			: to(to_), rev(rev_), flow(flow_), cap(cap_), res(res_), cost(cost_) {}
	};
	
	int n;
	vector<vector<edge>> g;
	vector<int> par_idx, par;
	T inf;
	vector<T> dist;

	mcmf(int n_) : n(n_), g(n), par_idx(n), par(n), inf(numeric_limits<T>::max() / 3) {}

	void add(int u, int v, int w, T cost) {
		edge a = edge(v, g[v].size(), 0, w, cost, false);
		edge b = edge(u, g[u].size(), 0, 0, -cost, true);
		
		g[u].push_back(a);
		g[v].push_back(b);
	}
	
	bool dijkstra(int s, int t, vector<T>& pot) {
			priority_queue<pair<T, int>, vector<pair<T, int>>, greater<>> q;
			dist = vector<T>(g.size(), inf);
			dist[s] = 0;
			q.emplace(0, s);
			while (q.size()) {
				auto [d, v] = q.top();
				q.pop();
				if (dist[v] < d) continue;
				for (int i = 0; i < g[v].size(); i++) {
					auto [to, rev, flow, cap, res, cost] = g[v][i];
					cost += pot[v] - pot[to];
					if (flow < cap and dist[v] + cost < dist[to]) {
						dist[to] = dist[v] + cost;
						q.emplace(dist[to], to);
						par_idx[to] = i, par[to] = v;
					}
				}
			}
			return dist[t] < inf;
	}

	pair<int, T> min_cost_flow(int s, int t, int flow = INF) {
		vector<T> pot(g.size(), 0);

		int f = 0;
		T ret = 0;
		while (f < flow and dijkstra(s, t, pot)) {
			for (int i = 0; i < g.size(); i++)
				if (dist[i] < inf) pot[i] += dist[i];

			int mn_flow = flow - f, u = t;
			while (u != s){
				mn_flow = min(mn_flow,
					g[par[u]][par_idx[u]].cap - g[par[u]][par_idx[u]].flow);
				u = par[u];
			}

		
			ret += pot[t] * mn_flow;

			u = t;
			while (u != s) {
				g[par[u]][par_idx[u]].flow += mn_flow;
				g[u][g[par[u]][par_idx[u]].rev].flow -= mn_flow;
				u = par[u];
			}

			f += mn_flow;
		}

		return make_pair(f, ret);
	}

	vector<pair<int, int>> min_cut() {
		vector<bool> vis(n, false);

		queue<int> f; f.push(0); vis[0] = true;

		while(!f.empty()) {
			auto v = f.front(); f.pop();

			for(auto& edges : g[v]) {
				if(edges.flow < edges.cap && !vis[edges.to]) {
					vis[edges.to] = 1;
					f.push(edges.to);
				}
			}
		}
		vector<pair<int, int>> out;

		for(int i = 0; i < n; i++) {
			for(auto& edge : g[i]) {
				if(vis[i] && !vis[edge.to] && !edge.res) {
					out.push_back({i, edge.to});
				}		
			}
		}

		return out;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	mcmf<int> flow(n);
	for(int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		flow.add(a, b, 1, 1);
		flow.add(b, a, 1, 1);
	}

	cout << flow.min_cost_flow(0, n - 1).first << '\n';
	
	for(auto [x, y] : flow.min_cut()) {
		cout << x + 1 << " " << y + 1<< '\n';
	}	
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

