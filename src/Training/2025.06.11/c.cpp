#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	if(n == 1){
		cout << "! " << 1 << '\n';
		return;
	}
	int a1, a2;
	cout << "? " << 1 << '\n';
	cout.flush();
	cin >> a1;
	cout << "? " << 2 << '\n';
	cout.flush();
	cin >> a2;
	if(a1 < a2){
		cout << "! " << 1 << '\n';
		return;
	}
	cout << "? " << n << '\n';
	cout.flush();
	cin >> a1;
	cout << "? " << n - 1 << '\n';
	cout.flush();
	cin >> a2;
	if(a1 < a2){
		cout << "! " << n << '\n';
		return;
	}
	auto check = [&](int x)-> int{
		vector<int> a(3);
		for(int i = x - 1; i <= x + 1; i ++){
			cout << "? " << i << '\n';
			cout.flush();
			cin >> a[i - x + 1];
		}
		if(a[1] < a[0] && a[1] < a[2])
			return 1;
		if(a[0] > a[2])
			return 2;
		if(a[0] < a[2])
			return 0;
	};
	int l = 2, r = n - 1;
	while(l <= r){
		int mid = (l + r) >> 1;
		int res = check(mid);
		if(res == 1){
			cout << "! " << mid << '\n';
			break;
		}
		if(res == 0)
			r = mid - 1;
		else
			l = mid + 1;
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