#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {//巧妙构造题
	int n;
	cin >> n;
	vector<int> vis(n + 1), p;
	for(int i = 2; i <= n; i ++){
		if(!vis[i]){
			p.push_back(i);
		}
		for(int j = 0; j < p.size() && p[j] <= n / i; j ++){
			vis[p[j] * i] = true;
			if(i % p[j] == 0){
				break;
			}
		}
	}
	vector<int> a(p.size()), res(n + 1), mp(n + 1);
	for(int i = p.size() - 1; i >= 0; i --){
		vector<int> arr;
		for(int j = 2 * p[i]; j <= n; j += p[i]) {
			if(mp[j]){
				continue;
			}
			mp[j] = true;
			arr.push_back(j);
		}
		arr.push_back(p[i]);
		int pos = p[i];
		for(auto e : arr){
			res[pos] = e;
			while(pos <= n && res[pos]){
				pos += p[i];
			}
		}
	}
	for(int i = 1; i <= n; i ++){
		if(!res[i]){
			res[i] = i;
		}
		cout << res[i] << ' ';
	}
	cout << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}