#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	int l = 1, r = n;
	while(l + 1 < r){
		int mid = (l + r) >> 1;

		cout << "? " << l << ' ' << mid<< '\n';
		cout.flush();

		int cnt1 = 0;
		for(int i = l; i <= mid; i ++){
			int x;
			cin >> x;
			if(x >= l && x <= mid)
				cnt1 ++;
		}
		if((cnt1 & 1))
			r = mid;
		else
			l = mid;
	}
	cout << "? " << l << ' ' << l << '\n';
	cout.flush();
	int x1;
	cin >> x1;

	if(l == x1)
		cout << "! " << x1 << '\n';
	else
		cout << "! " << r << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	// ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}