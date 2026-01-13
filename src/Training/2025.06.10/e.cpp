#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

bool isprime(i64 x){
	for(int i = 2; i <= x / i; i ++)
		if(x % i == 0)
			return false;
	return true;
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i ++)
		cin >> a[i];

	vector<int> d;
	if(n != 1)
		d.push_back(1);

	int x = n;//分解出所有可能的子数组大小，即n的所有因数
	for(int i = 2; i <= x / i; i ++){
		if(x % i == 0){
			d.push_back(i);
			if(x / i != i)
				d.push_back(x / i);
		}
	}

	int ans = 1;
	for(auto e : d){
		vector<i64> s;//用来记录子数组之间两两对应的数字的差值
		for(int i = 0; i < n - e; i ++){
			i64 x = abs(a[i] - a[i + e]);
			if(x != 0)
				s.push_back(x);
		}
		if(!s.size()){//如果所有差值都是0代表所有子数组相同
			ans ++;
			continue;
		}
		i64 g = s.front();//所有差值的gcd代表可以取得的m之一
		for(auto v : s)
			g = __gcd(g, v);
		// cout << e << " " << g << '\n';
		if(g == 1)//gcd是1的时候代表无解
			continue;
		ans ++;
	}
	cout << ans << '\n';
	// cout << '\n';
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}