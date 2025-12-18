#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(3);
	if(n & 1){
		a[0] = 1;
		n -= 1;
		a[1] = n / 2, a[2] = n / 2;
	}else{
		if((n / 2) & 1){
			a[0] = 2;
			a[1] = a[2] = n / 2 - 1;
		}else{
			a[0] = n / 2;
			a[1] = a[2] = n / 4;
		}
	}

	for(int i = 0; i < 3; i ++)
		cout << a[i] << " ";
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