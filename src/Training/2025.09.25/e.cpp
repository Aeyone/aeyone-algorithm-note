#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(n, vector<int> (m));
	vector<int> cnt(n);
	int sum = 0;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < m; j ++){
			cin >> a[i][j];
			cnt[i] += (a[i][j] == 1);
		}
		sum += cnt[i];
	}
	if(sum % n != 0){
		cout << -1 << '\n';
		return;
	}
	vector<array<int, 3>> ans;
	for(int y = 0; y < m; y ++){
		int p1 = 0, p2 = 0;
		while(p1 < n && p2 < n){
			while(p1 < n && !(cnt[p1] < sum / n && !a[p1][y])){
				p1 ++;
			}
			while(p2 < n && !(cnt[p2] > sum / n && a[p2][y])){
				p2 ++;
			}
			if(p1 < n && p2 < n){
				ans.push_back({p1 + 1, p2 + 1, y + 1});
				cnt[p1] ++, cnt[p2] --;
				a[p1][y] = 1, a[p2][y] = 0;
			}
		}
	}
	cout << ans.size() << '\n';
	for(auto [x, y, z] : ans){
		cout << x << ' ' << y << ' ' << z << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}