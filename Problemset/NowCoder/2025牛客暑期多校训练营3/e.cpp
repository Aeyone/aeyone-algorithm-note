#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
const int MAX = 5e6 + 10;
vector<int> p, isp(MAX + 1);

void build_primes(){
	vector<bool> vis(MAX + 1);
	for(int i = 2; i <= MAX; i ++){
		if(!vis[i])
			p.push_back(i), isp[i] = 1;
		for(int j = 0; j < p.size() && p[j] <= MAX / i; j ++){
			vis[p[j] * i] = true;
			if(i % p[j] == 0)
				break;
		}
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &e : a)
		cin >> e;
	if(n & 1){
		cout << "YES" << '\n';
		return;
	}
	if(n == 2 && a[0] != a[1]){
		cout << "NO" << '\n';
		return;
	}
	unordered_map<int, int> mp;
	auto divide = [&](int x)->void{
		for(int i = 0; (i < p.size() && p[i] <= x); i ++){
			int s = 0;
			if(isp[x]){
				mp[x] ++;
				return;
			}
			while(x % p[i] == 0){
				x /= p[i];
				s ++;
			}
			mp[p[i]] += s;
		}
		if(x > 1)
			mp[x] ++;
	};

	for(int i = 0; i < n; i ++)
		divide(a[i]);
	
	bool ok = true;
	for(auto [num, cnt] : mp)
		ok &= (cnt % 2 == 0);
	
	if(ok)
		cout << "YES" << '\n';
	else
		cout << "NO" << '\n';
	
}

signed main() {
//	freopen("../data/data.in", "r", stdin), freopen("../data/data.in", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(nullptr);
	build_primes();
	int _ = 1;
	cin >> _;
	while (_ --)
		solve();
}