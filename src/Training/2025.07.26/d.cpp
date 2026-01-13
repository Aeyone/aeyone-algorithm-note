#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int u = n - 1, x = 0;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		if(a[i] != 1 && a[i] != -1)
			u = i, x = a[i];
	}
	int mx = x, mn = x, now = 0;
	for(int i = u; i < n; i ++){
		now += a[i];
		mx = max(mx, now);
		mn = min(mn, now);
	}
	int nowmx = mx, nowmn = mn;
	for(int i = u - 1; i >= 0; i --){
		nowmx += a[i];
		nowmn += a[i];
		mx = max(mx, nowmx);
		mn = min(mn, nowmn);
	}

	int len0 = 0, len1 = 0, sum = 0;
	for(int i = 0; i < u; i ++){
		sum = max(0, sum + a[i]);
		len1 = max(len1, sum);
	}
	sum = 0;
	for(int i = u + 1; i < n; i ++){
		sum = max(0, sum + a[i]);
		len1 = max(len1, sum);
	}

	sum = 0;
	for(int i = 0; i < u; i ++){
		sum = max(0, sum - a[i]);
		len0 = max(len0, sum);
	}
	sum = 0;
	for(int i = u + 1; i < n; i ++){
		sum = max(0, sum - a[i]);
		len0 = max(len0, sum);
	}

	vector<int> ans;
	for(int i = 0 - len0; i <= len1; i ++)
		ans.push_back(i);
	
	for(int i = mn; i <= mx; i ++)
		ans.push_back(i);

	sort(ans.begin(), ans.end());
	ans.erase(unique(ans.begin(), ans.end()), ans.end());

	cout << ans.size() << '\n';
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