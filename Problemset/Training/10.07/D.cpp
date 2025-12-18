#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {//大粪
	int n;
	cin >> n;
	i64 sum = 0;
	vector<int> a(n);
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		sum += a[i];
	}
	if(sum % n != 0){
		cout << "No" << '\n';
		return;
	}
	vector<array<int, 2>> b(n);
	bool ok = true;
	map<int, int> mp;
	for(int i = 0; i < n; i ++){
		int d = abs((sum / n) - a[i]);
		if(d == 0){
			continue;
		}
		ok &= (__builtin_popcount(d + (d & -d)) == 1);
		int hi = d + (d & -d), lo = (d & -d);
		b[i][(sum / n > a[i])] = hi;
		b[i][!(sum / n > a[i])] = lo;
		mp[b[i][1]] ++;
	}
	if(!ok){
		cout << "No" << '\n';
		return;
	}
	for(int i = 0; i < n; i ++){
		if(sum / n == a[i]){
			continue;
		}
		mp[b[i][1]] --;
		ok &= (mp[b[i][0]] > 0);
		mp[b[i][0]] --;
		mp[b[i][1]] ++;
	}
	if(ok){
		cout << "Yes" << '\n';
	}else{
		cout << "No" << '\n';
	}

}
signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}
/*

2 		7 		11 		12		12	 	16
+16 	+4 		+1		+2		+2		+2
-8		-1		-2 		-4 		-4 		-8

+8 		+3 		-1 		-2 		-2 		-6

*/