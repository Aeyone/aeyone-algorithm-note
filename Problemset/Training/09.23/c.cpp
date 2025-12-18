#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {//大粪1
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	vector<vector<array<int, 2>>> v;
	vector<array<int, 2>> tmp;
	tmp.push_back({0, -1});
	for(int l = 0, r = 0; l < n; l = r){
		while(r < n && a[r] != 0){
			tmp.push_back({a[r], r});
			r ++;
		}
		if(tmp.size() > 1){
			v.push_back(tmp);
			tmp.clear();
			tmp.push_back({0, -1});
		}else{
			r ++;
		}
	}
	array<int, 3> ans = {0, 1, 0};
	for(auto arr : v){
		int m = arr.size() - 1;
		vector<int> pre(m + 1), neg(m + 1);
		int idx = -1;
		for(int i = 1; i <= m; i ++){
			pre[i] = pre[i - 1] + (abs(arr[i][0]) == 2);
			neg[i] = neg[i - 1] + (arr[i][0] < 0);
			if(arr[i][0] < 0){
				idx = i;
			}
		}
		if(idx == -1){
			if(pre[m] > ans[0]){
				ans = {pre[m], arr[1][1], arr[m][1]};
			}
			continue;
		}
		for(int i = 1; i <= m; i ++){
			int y = m;
			if((neg[m] - neg[i - 1]) & 1){
				y = idx - 1;
			}
			if(pre[y] - pre[i - 1] > ans[0]){
				ans = {pre[y] - pre[i - 1], arr[i][1], arr[y][1]};
			}
		}
	}
	cout << ans[1] << ' ' << n - ans[2] - 1 << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}