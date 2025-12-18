#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
int path[100], vis[100], n;
vector<string> ans;

void dfs(int num, int cnt, int sum){
	if(sum == n){
		string s;
		for(int i = 0; i < cnt; i ++)
			s += (char)path[i];
		ans.push_back(s);
		return;
	}

	for(int i = 1; i <= n; i ++){
		if(i == num || sum + i > n)
			continue;
		path[cnt] = i;
		sum += i;
		dfs(i, cnt + 1, sum);
		sum -= i;
	}
}

void solve() {
	cin >> n;
	dfs(0, 0, 0);
	// cout << ans.size() << '\n';
	sort(ans.begin(), ans.end());
	for(auto s : ans){
		for(auto e : s)
			cout << (int)e << ' ';
		cout << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --)
		solve();
}