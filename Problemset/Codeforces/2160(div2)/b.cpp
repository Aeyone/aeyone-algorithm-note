#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n;
	cin >> n;
	vector<i64> a(n), res(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	
	int cur = 1;
	res[0] = 1;
	for(int i = 1; i < n; i ++){
		int d = a[i] - a[i - 1];
		if(i - d < 0){
			res[i] = ++ cur;
		}else{
			res[i] = res[i - d];
		}
	}
	for(auto e : res){
		cout << e << ' ';
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