#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;
	if(count(a.begin(), a.end(), 0) > 1){
		int l = -1, r = -2;
		for(int i = 0; i < n; i ++){
			if(a[i] != i + 1){
				if(l == -1)
					l = i;
				r = i;
			}
		}
		cout << r - l + 1 << '\n';
	}else{
		vector<int> mp(n + 1);
		for(int i = 0; i < n; i ++)
			mp[a[i]] = true;
		
		int num = -1;
		for(int i = 1; i <= n; i ++)
			if(!mp[i])
				num = i;

		int l = -1, r = -2;
		for(int i = 0; i < n; i ++){
			if(a[i] == 0)
				a[i] = num;
			if(a[i] != i + 1){
				if(l == -1)
					l = i;
				r = i;
			}
		}
		cout << r - l + 1 << '\n';
	}
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}