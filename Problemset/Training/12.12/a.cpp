#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

const int MOD = 998244353;

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<array<int, 2>>> r(n + 1), c(m + 1);
	for(int i = 0; i < k; i ++) {
		int x, y;
		cin >> x >> y;
		r[x].push_back({x, y});
		c[y].push_back({x, y});
	}
	set<array<int, 2>> st;
	int q;
	cin >> q;
	while(q --){
		int sign;
		cin >> sign;
		int ans = 0;
		if(sign == 1){
			int x;
			cin >> x;
			for(auto e : r[x]){
				if(st.find(e) == st.end()){
					ans ++;
					st.insert(e);
				}
			}
			r[x].clear();
		}else{
			int y;
			cin >> y;
			for(auto e : c[y]){
				if(st.find(e) == st.end()){
					ans ++;
					st.insert(e);
				}
			}
			c[y].clear();
		}
		cout << ans << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}