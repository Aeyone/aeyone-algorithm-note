#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	map<int, int> cnt;
	vector<int> a(n);
	int mx = 0, mn = 0x3f3f3f3f;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		cnt[a[i]] ++;
		mx = max(mx, a[i]);
		mn = min(mn, a[i]);
	}

	if(cnt.size() == 1){
		if(n >= 2 * mx || n == mx + 1 || mx == 1)
			cout << "Other" << '\n';
		else
			cout << "Lie" << '\n';
	}else if(cnt.size() == 2){
		if((mx == cnt[mx] - 1 && mn == cnt[mx]) ||(mn == cnt[mn] - 1 && mx == cnt[mn]))
			cout << "Other" << '\n';
		else
			cout << "Lie" << '\n';
	}else 
		cout << "Lie" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}