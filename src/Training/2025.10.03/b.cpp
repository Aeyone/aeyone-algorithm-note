#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n);
	map<int, int> mp;
	bool ok = false;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		mp[a[i]] ++;
		ok |= (mp[a[i]] >= 2);//每个数必须不同
	}
	vector<vector<int>> f(n + 1, vector<int>(n));//f[i][r]为整个数组中的数除i的余数为r的数量
	for(int i = 2; i <= n; i ++){
		for(int j = 0; j < n; j ++){
			int r = a[j] % i;
			f[i][r] ++;
		}
	}
	for(int i = 2; i <= n; i ++){
		bool flag = true;
		for(int r = 0; r < i; r ++){
			flag &= (f[i][r] >= 2);//如果对于某个数字i，对数组加上任意x都存在至少两个数同余0，那么一定不可能成为互质数组。
		}
		ok |= flag;
	}
	if(ok){
		cout << "NO" << '\n';
	}else{
		cout << "YES" << '\n';
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