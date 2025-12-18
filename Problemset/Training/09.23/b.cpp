#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {//二分好题 n*n优化至nlogn
	string s;
	cin >> s;
	int n = s.size();
	s = "x" + s;
	vector<array<int, 2>> pre(n + 1);
	for(int i = 1; i <= n; i ++){
		pre[i][0] += pre[i - 1][0] + (s[i] == '0');
		pre[i][1] += pre[i - 1][1] + (s[i] == '1');
	}
	int c1 = count(s.begin(), s.end(), '1'), res = inf;
	if(c1 == n || c1 == 0){
		cout << 0 << '\n';
		return;
	}
	for(int i = 1; i <= n; i ++) if(s[i] == '1'){
		int l = i, r = n, ans = -1;
		while(l <= r){
			int mid = (l + r) / 2;
			int cnt0 = pre[mid][0] - pre[i - 1][0];
			int cnt1 = c1 - (pre[mid][1] - pre[i - 1][1]);
			if(cnt1 >= cnt0)
				ans = cnt1, l = mid + 1;
			else
				r = mid - 1;
		}
		res = min(res, ans);
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}