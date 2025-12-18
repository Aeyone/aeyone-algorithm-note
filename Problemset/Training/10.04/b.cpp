#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

#define mod 998244353
#define inf 0x7f7f7f7f
#define infll 0x7f7f7f7f7f7f7f7fll

void solve() {//超级大粪
	i64 a, b, c, k;
	cin >> a >> b >> c >> k;

	int LB = pow(10, b - 1), RB = pow(10, b) - 1, Lsum = pow(10, c) - 1;
	int la, lb;
	if(c == max(a, b) + 1){//需要进位
		if(a <= b){
			la = pow(10, a - 1);
			lb = pow(10, c - 1) - la;
		}else{
			la = pow(10, c - 1) - RB;
			lb = pow(10, b) - 1;
		}
	}else if(c == max(a, b)){//不需要进位
		la = pow(10, a - 1);
		lb = pow(10, b - 1);
	}else{
		cout << -1 << '\n';
		return;
	}
	// cout << la  << ' ' << lb << '\n';
	int A = la, B = lb;
	int ra = min(Lsum - lb, (int)pow(10, a) - 1), rb = min(Lsum - A, RB);
	int d = rb - lb + 1;

	while(A < ra && k - d >= 1){//先确定A
		A ++, k -= d;
		B -= (B > LB);
		rb = min(Lsum - A, RB);
		d = rb - B + 1;
	}

	while(B < rb && k > 1){
		B ++, k --;
	}
	if(k == 1){
		cout << A << " + " << B << " = " << A + B << '\n';
	}else{
		cout << -1 << '\n';
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int _ = 1;
	cin >> _;
	while (_ --){
		solve();
	}
	// for(int i = 1; i <= 100; i ++){
	// 	cout << "2 1 3 " << i << '\n';
	// }
}