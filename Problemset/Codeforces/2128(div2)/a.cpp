#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, c;
	cin >> n >> c;
	vector<int> a(n), b(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	map<int, bool> mp;
	for(int i = 0; i < n; i ++){
		i64 num = a[i];
		while(num <= c){
			b[i] ++;
			num = 2 * num;
		}
	}
	sort(b.begin(), b.end());
	for(int i = 0; i < n; i ++){
		if(b[i] > 0){
			for(int j = 1; j <= b[i]; j ++)
				if(!mp[j]){
					mp[j] = true;
					break;
				}
		}
	}
	cout << n - mp.size() << '\n';

}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}