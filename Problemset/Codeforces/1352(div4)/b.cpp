#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n, k;
	cin >> n >> k;
	if(k % 2 == 0 && n & 1){
		cout << "NO" << '\n';
		return;
	}
	int res = 0;
	vector<int> ans;
	if(k & 1){
		if(n % 2 == 0){
			ans.push_back(n - (k - 1) * 2);
			while(-- k)
				ans.push_back(2);
		}
		else{
			ans.push_back(n - k + 1);
			while(-- k)
				ans.push_back(1);
		}
	}else{
		ans.push_back(n - k + 1);
		while(-- k)
			ans.push_back(1);
	}
	if(ans.front() > 0){
		cout << "YES" << '\n';
		for(int e : ans)
			cout << e << ' ';
		cout << '\n';
	}else
		cout << "NO" << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}