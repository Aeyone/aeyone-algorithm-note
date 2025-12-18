#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

void solve() {
	int n, m;
	cin >> n >> m;
	vector<i64> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	auto check = [&](i64 x)->bool{
		i64 cnt = 0, sum = 0;
		if(*max_element(a.begin(), a.end()) > x){
			return false;
		}
		for(int r = 0; r < n;){
			while(r < n && sum + a[r] <= x){
				sum += a[r ++];
			}
			sum = 0, cnt ++;
		}
		return (cnt <= m);
	};
	i64 l = 0, r = 1e9, ans = 0;
	while(l <= r){
		i64 mid = (l + r) / 2;
		if(check(mid)){
			ans = mid, r = mid - 1;
		}else{
			l = mid + 1;
		}
	}	
	cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	// cin >> _;
	while (_ --){
		solve();
	}
}