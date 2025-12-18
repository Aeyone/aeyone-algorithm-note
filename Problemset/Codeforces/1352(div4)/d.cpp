#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	bool ok = true;
	int rnd = 1, backup = 0, l = 0, r = n - 1;
	int x = 0, y = 0;
	while(ok){
		if(rnd & 1){
			int tmp = 0;
			while(tmp <= backup && l <= r)
				tmp += a[l ++]; 
			ok &= (l <= r);
			backup = tmp;
			x += tmp;
		}else{
			int tmp = 0;
			while(tmp <= backup && l <= r)
				tmp += a[r --]; 
			ok &= (l <= r);
			backup = tmp;
			y += tmp;
		}
		if(ok)
			rnd ++;
	}
	cout << rnd << " " << x << " " << y << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}