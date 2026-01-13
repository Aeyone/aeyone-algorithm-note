#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {//模拟
	int n;
	cin >> n;
	vector<int> a(2 * n);
	multiset<int> st;
	for(int i = 0; i < 2 * n; i ++){
		cin >> a[i];
		st.insert(a[i]);
	}
	sort(a.begin(), a.end());
	vector<array<int, 2>> path(n);
	auto dfs = [&](auto &&self, int x, int cnt)->bool{
		if(st.size() == 0){
			cout << "YES" << '\n';
			cout << path[0][0] + path[0][1] << '\n';
			for(auto [p, q] : path){
				cout << p << ' ' << q << '\n';
			}
			return true;
		}
		int p = *(--st.end()), q = x - p;
		if((p == q && st.count(p) <= 1) || st.find(q) == st.end()){
			return false;
		}
		st.erase(st.find(p)), st.erase(st.find(q));
		path[cnt] = {p, q};
		bool ok = self(self, p, cnt + 1);
		st.insert(p), st.insert(q);
		return ok;
	};
	bool ok = false;
	int x = *(--st.end());
	st.erase(st.find(x));
	for(int i = 0; i < 2 * n - 1; i ++){
		path[0] = {x, a[i]};
		st.erase(st.find(a[i]));
		if(dfs(dfs, x, 1)){
			return;
		}
		st.insert(a[i]);
	}
	cout << "NO" << '\n';	
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}