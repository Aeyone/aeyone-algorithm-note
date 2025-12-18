#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];
		
	sort(a.begin(), a.end());
	i64 res = 0;
	for(int i = 0; i < n; i ++){
		for(int j = i + 1; j < n - 1; j ++){
			if(i + 2 >= n)
				continue;

			int l = j + 1, r = n - 2, ll = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(a[mid] + a[i] + a[j] > a[n - 1])
					ll = mid, r = mid - 1;
				else
					l = mid + 1;
			}

			l = ll, r = n - 2;
			int rr = -1;
			while(l <= r){
				int mid = (l + r) >> 1;
				if(a[i] + a[j] > a[mid])
					rr = mid, l = mid + 1;
				else
					r = mid - 1;
			}

			int ans = -1;
			if(rr != -1 && ll != -1)
				ans = rr - ll + 1;

			if(ans != -1)
				res += ans;
			
			if(a[i] + a[j] > a[n - 1])
				res ++;
		}
	}
	cout << res << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}