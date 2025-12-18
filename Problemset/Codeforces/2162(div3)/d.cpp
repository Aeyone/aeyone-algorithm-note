#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define MOD 998244353
#define INF 0x7f7f7f7f
#define INFLL 0x7f7f7f7f7f7f7f7fLL

/*
3 1 2

3 2 2
*/
int query(int sign, int l, int r){
	cout << sign << ' ' << l << ' ' << r << endl;
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n;
	cin >> n;
	int L = 0, R = n + 1;
	int l = 1, r = n;
	while(l <= r){
		int mid = (l + r) / 2;
		if(query(1, 1, mid) == query(2, 1, mid)){
			L = mid, l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	l = 1, r = n;
	while(l <= r){
		int mid = (l + r) / 2;
		if(query(1, mid, n) == query(2, mid, n)){
			R = mid, r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << "! " << L + 1 << ' ' << R - 1 << '\n';
}

signed main() {
	// ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
}