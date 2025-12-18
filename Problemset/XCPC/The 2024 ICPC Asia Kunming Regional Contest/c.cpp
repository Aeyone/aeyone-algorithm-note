#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL
string lltos(i64 num, int base){
	if(num == 0){
		return "0";
	}
	string idx = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string res;
	while(num){
		res += idx[num % base];
		num /= base;
	}
	reverse(res.begin(), res.end());
	return res;
}

int solve(int n, int k) {
	vector<int> a(n + 1);
	while(1){
		vector<int> idx;
		int cnt = 0;
		for(int i = 1; i <= n; i ++){
			if(a[i] == 1){
				cout << "d ";
			}else{
				cout << ++ cnt << ' ';
			}
			// cout << a[i] << ' ';
			if(i % k == 0){
				cout << " | ";
			}
			if(!a[i]){
				idx.push_back(i);
			}
		}
		cout << '\n';
		if(idx.size() == 1){
			int ans = idx.back();
			cout << "n = " << n << "\tk = " << k << "\t## " << ans;
			// cout << "\ttobase = " << lltos(ans, k) << '\n';
			cout << '\n';
			return ans;
		}
		for(int i = 0; i < idx.size(); i += k){
			a[idx[i]] = 1;
		}
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve(36, 8);
		// map<int, int> mp;
		// for(int i = 2; i <= 1000; i ++){
		// 	mp[solve(i, 3)] ++;
		// }
		// for(auto [x, y] : mp){
		// 	cout << x << ' ' << y << '\n';
		// }
	}
}