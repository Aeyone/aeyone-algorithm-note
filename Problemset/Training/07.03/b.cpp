#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int inf = 0x3f3f3f3f;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), pre(n), suf(n);
	vector<i64> pres(n), sufs(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	//处理前缀第一个不相同的数的位置和前缀和
	pre[0] = -1, pres[0] = a[0];
	for(int i = 1; i < n; i ++){
		pre[i] = (a[i] == a[i - 1] ? pre[i - 1] : i - 1);
		pres[i] = pres[i - 1] + a[i];
	}
	//处理后缀第一个不相同的数的位置和后缀和
	suf[n - 1] = n, sufs[n - 1] = a[n - 1];
	for(int i = n - 2; i >= 0; i --){
		suf[i] = (a[i] == a[i + 1] ? suf[i + 1] : i + 1);
		sufs[i] = sufs[i + 1] + a[i];
	}
	if(n == 1){
		cout << -1 << '\n';
		return;
	}
	vector<int> ans(n, -1);
	ans[0] = (a[1] > a[0] ? 1 : -1);
	ans[n - 1] = (a[n - 2] > a[n - 1] ? 1 : -1);
	for(int i = 1; i < n - 1; i ++)
		if(a[i - 1] > a[i] || a[i + 1] > a[i])
			ans[i] = 1;

	for(int i = 0; i < n; i ++){
		if(ans[i] == 1)
			continue;

		int l = 0, r = pre[i];
		int ans1 = -1;
		if(r >= 0 && r == i - 1)
			r = pre[r];
		//找左边
		while(l <= r){
			int mid = (l + r) >> 1;
			if(sufs[mid] - sufs[i] > a[i])
				ans1 = mid, l = mid + 1;
			else
				r = mid - 1;
		}

		l = suf[i], r = n - 1;
		int ans2 = -1;
		if(l < n && l == i + 1)
			l = suf[l];
		//找右边
		while(l <= r){
			int mid = (l + r) >> 1;
			if(pres[mid] - pres[i] > a[i])
				ans2 = mid, r = mid - 1;
			else
				l = mid + 1;
		}

		if(ans1 != -1 && ans2 != -1)
			ans[i] = min(i - ans1, ans2 - i);
		else if(ans1 != -1)
			ans[i] = i - ans1;
		else if(ans2 != -1)
			ans[i] = ans2 - i;
	}
	for(auto e : ans)
		cout << e << ' ';
	cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}