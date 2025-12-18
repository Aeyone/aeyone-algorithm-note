#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
vector<int> p;

void build(int MAX){
	vector<bool> vis(MAX + 1);
	for(int i = 2; i <= MAX; i ++){
		if(!vis[i])
			p.push_back(i);
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
	vector<int> a(n), b(n);
	map<int, int> mp;
	auto divide = [&](int x, int sign)->bool{
		bool ok = false;
		for(int i = 0; i < p.size() && x > p[i]; i ++){
			if(x % p[i] == 0){
				ok |= (mp[p[i]] >= 1);
				if(sign){
					mp[p[i]] ++;
				}
			}
			while(x % p[i] == 0){
				x /= p[i];
			}
		}
		if(x > 1){
			ok |= (mp[x] >= 1);
			if(sign){
				mp[x] ++;
			}
		}
		return ok;
	};
	bool ok = false;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		ok |= divide(a[i], 1);
	}
	for(int i = 0; i < n; i ++){
		cin >> b[i];
	}
	if(ok){
		cout << 0 << '\n';
		return;
	}
	for(int i = 0; i < n; i ++){
		ok |= divide(a[i] + 1, 0);
	}
	if(ok){
		cout << 1 << '\n';
	}else{
		cout << 2 << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	build(500);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}