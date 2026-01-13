#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
	if(n == 1){
		cout << a[0] << '\n';
		return;
	}
	int pos = 0, p4 = 0;
	int ans = 0;
	while(pos < n){
		ans += a[pos];
		if(pos + 1 >= n || pos + 2 >= n || pos + 3 >= n)
			break;

		p4 += a[pos + 1];
		if(pos + 4 >= n && a[pos + 2] == 1 && a[pos + 3] == 1){
			ans += p4;
			break;
		}
		if(p4 == 0){
			pos = min(n - 1, pos + 4);
			for(int i = pos; i >= pos - 2; i --)
				if(a[i] == 0){
					pos = i;
					break;
				}
		}else{
			if(!a[pos + 2] && a[pos + 3])
				pos += 2;
			else if(pos + 4 < n && a[pos + 2] && a[pos + 3] && !a[pos + 4])
				pos += 4 , ans += p4;
			else
				pos += 3;
		}
	}
	cout << ans << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}